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

import assert from 'assert';
import url from 'url';

import { domainToASCII } from '../index.js';

let maxUnicode = 0x10FFFF;

let diff = [];

for (let codePoint = 0; codePoint <= maxUnicode; codePoint++) {
  let character = String.fromCodePoint(codePoint);
  let thisPackage = domainToASCII(character);
  let native = url.domainToASCII(character);
  if (thisPackage !== native) {
    diff.push({
      character,
      codePoint,
      codePointInHex: '0x' + codePoint.toString(16),
      thisPackage,
      native
    });
  }
}

console.log(diff);
console.log();

console.log(`${diff.length} out of ${maxUnicode + 1} code points differ`);
