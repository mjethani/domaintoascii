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

let toASCII = await (async function () {
  let url = new URL('encoder.wasm', import.meta.url);

  let module = null;

  if (typeof fetch === 'undefined') {
    let { readFile } = await import('node:fs/promises');
    let { buffer } = new Uint8Array(await readFile(url));

    module = await WebAssembly.compile(buffer);

  } else {
    module = await WebAssembly.compileStreaming(fetch(url));
  }

  let memory = new WebAssembly.Memory({ initial: 3, maximum: 3 });
  let instance = await WebAssembly.instantiate(module, { env: { memory } });

  let { punycode_encode,
        punycode_get_input_ptr,
        punycode_get_output_ptr,
        idna_map,
        idna_get_input_ptr,
        idna_get_output_ptr } = instance.exports;

  let buf8 = new Uint8Array(memory.buffer);
  let buf32 = new Uint32Array(memory.buffer);

  let punycodeInputPtr = punycode_get_input_ptr();
  let punycodeOutputPtr = punycode_get_output_ptr();

  let idnaInputPtr = idna_get_input_ptr();
  let idnaOutputPtr = idna_get_output_ptr();

  function wasmIDNAMap(domain) {
    let inputPtr32 = idnaInputPtr >> 2;
    let outputPtr32 = idnaOutputPtr >> 2;

    let initialInputPtr32 = inputPtr32;

    for (let character of domain) {
      // Maximum input size.
      if (inputPtr32 - initialInputPtr32 === 1023)
        return '';

      buf32[++inputPtr32] = character.codePointAt(0);
    }

    buf32[initialInputPtr32] = inputPtr32 - initialInputPtr32;

    if (idna_map() !== 0)
      return '';

    let result = '';
    for (let i = outputPtr32 + 1, n = outputPtr32 + 1 + buf32[outputPtr32]; i < n; i++)
      result += String.fromCodePoint(buf32[i]);
    return result;
  }

  function wasmPunycodeEncode(label) {
    let inputPtr32 = punycodeInputPtr >> 2;
    let outputPtr8 = punycodeOutputPtr;

    let initialInputPtr32 = inputPtr32;

    let basicOnly = true;

    for (let character of label) {
      // Maximum input size.
      if (inputPtr32 - initialInputPtr32 === 1023)
        return '';

      let codePoint = character.codePointAt(0);

      if (codePoint >= 0x80)
        basicOnly = false;

      buf32[++inputPtr32] = codePoint;
    }

    buf32[initialInputPtr32] = inputPtr32 - initialInputPtr32;

    if (punycode_encode() !== 0)
      return '';

    let result = '';
    for (let i = outputPtr8 + 1, n = outputPtr8 + 1 + buf8[outputPtr8]; i < n; i++)
      result += String.fromCodePoint(buf8[i]);
    return basicOnly ? result : 'xn--' + result;
  }

  return function (domain) {
    domain = wasmIDNAMap(domain);

    if (domain === '')
      return '';

    domain = domain.normalize('NFC');

    let ascii = '';
    let dotIndex = -1;

    while (true) {
      let nextDotIndex = domain.indexOf('.', dotIndex + 1);
      let label = domain.substring(dotIndex + 1,
                                   nextDotIndex === -1 ?
                                     domain.length :
                                     nextDotIndex);
      let encoded = wasmPunycodeEncode(label);
      if (encoded === '' && label !== '')
        return '';

      ascii += encoded;

      if (nextDotIndex === -1)
        break;

      ascii += '.';
      dotIndex = nextDotIndex;
    }

    return ascii;
  };
})();

function urlEncode(domain) {
  try {
    let { hostname } = new URL('ws://' + domain);
    return hostname;

  } catch (error) {
  }

  return '';
}

export function domainToASCII(domain) {
  if (domain === '')
    return '';

  // IPv6 address.
  if (domain[0] === '[' && domain[domain.length - 1] === ']')
    return urlEncode(domain);

  // Disallowed ASCII characters regardless of underlying implementation.
  if (/[\x00\t\n\r #%\/:\?@[\\\]]/.test(domain))
    return '';

  let ascii = /^[\x00-\x7F]*$/.test(domain) ?
                domain.toLowerCase() :
                toASCII(domain);

  if (/^\d+(\.\d+){0,3}\.?$/.test(ascii))
    return urlEncode(ascii);

  return ascii;
}
