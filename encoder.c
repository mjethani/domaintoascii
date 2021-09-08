/*
 * Copyright (c) 2021 Manish Jethani
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

// https://datatracker.ietf.org/doc/html/rfc3492

#include <stdlib.h>
#include <stdint.h>

int idna_disallow(uint32_t);

enum { BASE = 36, TMIN = 1, TMAX = 26, SKEW = 38,
       DAMP = 700, INITIAL_BIAS = 72, INITIAL_N = 0x80 };

enum { SUCCESS, BAD_INPUT, BIG_OUTPUT, OVERFLOW };

static uint32_t input[1024];
static uint8_t output[256];

uint32_t* get_input_ptr() { return input; }
uint8_t* get_output_ptr() { return output; }

static uint8_t encode_digit(uint32_t d) { return d + 22 + 75 * (d < 26); }

static uint32_t adapt(uint32_t delta, uint32_t numpoints, int firsttime) {
  uint32_t k;

  delta = firsttime ? delta / DAMP : delta >> 1;
  delta += delta / numpoints;

  for (k = 0; delta > ((BASE - TMIN) * TMAX) / 2; k += BASE)
    delta /= BASE - TMIN;

  return k + (BASE - TMIN + 1) * delta / (delta + SKEW);
}

int encode() {
  uint32_t input_length, n, delta, h, b, bias, j, m, q, k, t;
  size_t out, max_out;

  input_length = input[0];

  if (input_length > sizeof input - 1)
    return OVERFLOW;

  n = INITIAL_N;
  delta = 0;
  out = 1;
  max_out = sizeof output - 1;
  bias = INITIAL_BIAS;

  for (j = 1; j < input_length + 1; j++) {
    if (input[j] < 0x80) {
      if (max_out - out < 2)
        return BIG_OUTPUT;

      output[out++] = (uint8_t) input[j];

    } else if (input[j] > 0x10FFFF || idna_disallow(input[j])) {
      return BAD_INPUT;
    }
  }

  h = b = (uint32_t) (out - 1);

  if (b > 0 && b < input_length)
    output[out++] = 0x2D;

  while (h < input_length) {
    for (m = 0xFFFFFFFF, j = 1; j < input_length + 1; j++) {
      if (input[j] >= n && input[j] < m)
        m = input[j];
    }

    if (m - n > (0xFFFFFFFF - delta) / (h + 1))
      return OVERFLOW;

    delta += (m - n) * (h + 1);
    n = m;

    for (j = 1; j < input_length + 1; j++) {
      if (input[j] < n) {
        if (++delta == 0)
          return OVERFLOW;
      }

      if (input[j] == n) {
        for (q = delta, k = BASE;; k += BASE) {
          if (out >= max_out)
            return BIG_OUTPUT;

          t = k <= bias ? TMIN : k >= bias + TMAX ? TMAX : k - bias;
          if (q < t)
            break;

          output[out++] = encode_digit(t + (q - t) % (BASE - t));
          q = (q - t) / (BASE - t);
        }

        output[out++] = encode_digit(q);
        bias = adapt(delta, h + 1, h == b);
        delta = 0;
        h++;
      }
    }

    delta++;
    n++;
  }

  output[0] = (uint8_t) (out - 1);

  return SUCCESS;
}
