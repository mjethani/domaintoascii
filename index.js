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

let wasmEncode = await (async function () {
  let instance = null;
  let memory = null;

  try {
    if (typeof fetch === 'undefined') {
      let { readFile } = await import('fs/promises');
      let buffer = await readFile(new URL('encoder.wasm', import.meta.url));
      let module = await WebAssembly.compile(new Uint8Array(buffer).buffer);

      memory = new WebAssembly.Memory({ initial: 1, maximum: 1 });
      instance = await WebAssembly.instantiate(module, { env: { memory } });
    }
  } catch (error) {
  }

  if (instance === null)
    return null;

  let { encode, get_input_ptr, get_output_ptr } = instance.exports;

  let buf8 = new Uint8Array(memory.buffer);
  let buf32 = new Uint32Array(memory.buffer);

  let inputPtr = get_input_ptr();
  let outputPtr = get_output_ptr();

  return function wasmEncode(label) {
    let inputPtr32 = inputPtr >> 2;
    let initialInputPtr32 = inputPtr32;

    for (let character of label) {
      // Maximum input size.
      if (inputPtr32 - initialInputPtr32 === 1023)
        return '';

      buf32[++inputPtr32] = character.codePointAt(0);
    }

    buf32[initialInputPtr32] = inputPtr32 - initialInputPtr32;

    if (encode() !== 0)
      return '';

    let result = '';
    for (let i = outputPtr + 1, n = outputPtr + 1 + buf8[outputPtr]; i < n; i++)
      result += String.fromCodePoint(buf8[i]);
    return result === label ? result : ('xn--' + result);
  };
})();

function encode(label) {
  if (wasmEncode !== null)
    return wasmEncode(label);

  if (label === '' || label === '*' || !/[^a-z\d_*-]/.test(label))
    return label;

  try {
    let { hostname } = new URL('ws://' + label);
    return hostname;

  } catch (error) {
  }

  return '';
}

export function domainToASCII(domain) {
  let ascii = '';
  let dotIndex = -1;

  while (true) {
    let nextDotIndex = domain.indexOf('.', dotIndex + 1);
    let label = domain.substring(dotIndex + 1,
                                 nextDotIndex === -1 ?
                                   domain.length :
                                   nextDotIndex);
    ascii += encode(label);

    if (nextDotIndex === -1)
      break;

    ascii += '.';
    dotIndex = nextDotIndex;
  }

  return ascii;
}
