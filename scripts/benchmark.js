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

import { readFileSync } from 'fs';
import url from 'url';

import punycode from 'punycode/punycode.js';

import { domainToASCII } from '../index.js';

function run(impl, times) {
  let n = 0;

  for (let i = 0; i < times; i++) {
    for (let entry of entries)
      n += impl(entry).length;
  }

  return n;
}

let content = readFileSync('tests/data/public_suffix_list.dat', 'utf8');
let entries = content.split('\n')
              .map(line => line.trim())
              .map(line => line.replace(/\s*\/\/.*/, ''))
              .map(line => line.replace(/^!/, ''))
              .filter(line => line !== '');

let implementations = {
  'native': url.domainToASCII,
  'domaintoascii': domainToASCII,
  'punycode.js': punycode.toASCII,
  'domaintoascii { skipIDNA=true }': d => domainToASCII(d, { skipIDNA: true }),
};

for (let name in implementations) {
  let total = 0;

  console.time(name);
  total = run(implementations[name], 10);
  console.timeEnd(name);

  console.log(`Generated ${total.toLocaleString()} characters`);
  console.log();
}
