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

#include <stdlib.h>
#include <stdint.h>

#include "idna_tables-generated.h"

static uint32_t input[1024];
static uint32_t output[1024];

uint32_t* idna_get_input_ptr() { return input; }
uint32_t* idna_get_output_ptr() { return output; }

static uint32_t* map(uint32_t cp) {
  size_t i, l, h;

  l = 0;
  h = sizeof idna_tables_mapped / sizeof idna_tables_mapped[0] - 1;

  do {
    i = (l + h) >> 1;

    if (cp < idna_tables_mapped[i].key) {
      if (i == 0)
        break;

      h = i - 1;
    } else if (cp > idna_tables_mapped[i].key)
      l = i + 1;
    else
      return idna_tables_mapped[i].value;
  } while (l <= h);

  return NULL;
}

static int ignore(uint32_t cp) {
  size_t i, l, h;

  l = 0;
  h = sizeof idna_tables_ignored / sizeof idna_tables_ignored[0] - 1;

  do {
    i = (l + h) >> 1;

    if (cp < idna_tables_ignored[i][0]) {
      if (i == 0)
        break;

      h = i - 1;
    } else if (cp > idna_tables_ignored[i][1])
      l = i + 1;
    else
      return 1;
  } while (l <= h);

  return 0;
}

static int disallow(uint32_t cp) {
  size_t i, l, h;

  l = 0;
  h = sizeof idna_tables_disallowed / sizeof idna_tables_disallowed[0] - 1;

  do {
    i = (l + h) >> 1;

    if (cp < idna_tables_disallowed[i][0]) {
      if (i == 0)
        break;

      h = i - 1;
    } else if (cp > idna_tables_disallowed[i][1])
      l = i + 1;
    else
      return 1;
  } while (l <= h);

  return 0;
}

static int mark(uint32_t cp) {
  size_t i, l, h;

  l = 0;
  h = sizeof idna_tables_marks / sizeof idna_tables_marks[0] - 1;

  do {
    i = (l + h) >> 1;

    if (cp < idna_tables_marks[i][0]) {
      if (i == 0)
        break;

      h = i - 1;
    } else if (cp > idna_tables_marks[i][1])
      l = i + 1;
    else
      return 1;
  } while (l <= h);

  return 0;
}

int idna_map() {
  size_t i, j, out;
  uint32_t* value;

  out = 1;

  if ((size_t) input[0] > sizeof input - 1)
    return 1;

  for (i = 1; i <= (size_t) input[0]; i++) {
    if (ignore(input[i]))
      continue;

    if (disallow(input[i]))
      return 3;

    value = map(input[i]);

    if (value == NULL) {
      if (out >= sizeof output)
        return 2;

      // Note: This step is to be performed after normalization, but it does
      // not seem to matter in practice.
      if ((out == 1 || output[out - 1] == 0x2E) && mark(input[i]))
        return 4;

      output[out++] = input[i];
    } else {
      if ((out == 1 || output[out - 1] == 0x2E) && mark(*value))
        return 4;

      // Maximum 6 code points.
      for (j = 0; j < 6 && *value != 0; j++, value++) {
        if (out >= sizeof output)
          return 2;

        output[out++] = *value;
      }
    }
  }

  output[0] = (uint32_t) (out - 1);

  return 0;
}
