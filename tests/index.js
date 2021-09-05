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

import { strict as assert } from 'assert';
import { readFileSync } from 'fs';
import url from 'url';

import { domainToASCII } from '../index.js';

let idnaExamples = [
  // https://en.wikipedia.org/wiki/IDN_Test_TLDs
  'مثال.إختبار',
  'مثال.آزمایشی',
  '例子.测试',
  '例子.測試',
  'ример.испытание',
  'उदाहरण.परीक्षा',
  'παράδειγμα.δοκιμή',
  '실례.테스트',
  'בײַשפּיל.טעסט',
  '例え.テスト',
  'உதாரணம்.பரிட்சை',

  // http://www.i18nguy.com/markup/idna-examples.html
  "افغانستا.icom.museum",
  "الجزائر.icom.museum",
  "österreich.icom.museum",
  "বাংলাদেশ.icom.museum",
  "беларусь.icom.museum",
  "belgië.icom.museum",
  "българия.icom.museum",
  "تشادر.icom.museum",
  "中国.icom.museum",
  "القمر.icom.museum",
  "κυπρος.icom.museum",
  "českárepublika.icom.museum",
  "مصر.icom.museum",
  "ελλάδα.icom.museum",
  "magyarország.icom.museum",
  "ísland.icom.museum",
  "भारत.icom.museum",
  "ايران.icom.museum",
  "éire.icom.museum",
  "איקו״ם.ישראל.museum",
  "日本.icom.museum",
  "الأردن.icom.museum",
  "қазақстан.icom.museum",
  "한국.icom.museum",
  "кыргызстан.icom.museum",
  "ລາວ.icom.museum",
  "لبنان.icom.museum",
  "македонија.icom.museum",
  "موريتانيا.icom.museum",
  "méxico.icom.museum",
  "монголулс.icom.museum",
  "المغرب.icom.museum",
  "नेपाल.icom.museum",
  "عمان.icom.museum",
  "قطر.icom.museum",
  "românia.icom.museum",
  "россия.иком.museum",
  "србијаицрнагора.иком.museum",
  "இலங்கை.icom.museum",
  "españa.icom.museum",
  "ไทย.icom.museum",
  "تونس.icom.museum",
  "türkiye.icom.museum",
  "украина.icom.museum",
  "việtnam.icom.museum",
];

let invalidInputs = [
  '',
  'e x a m p l e',
  '?foo',
];

let specialCases = [
  { input: '-', output: '-' },
  { input: '--', output: '--' },
  { input: '---', output: '---' },
  { input: '----', output: '----' },
  { input: '_', output: '_' },
  { input: '__', output: '__' },
  { input: '.', output: '.' },
  { input: '..', output: '..' },
  { input: '127.0.0.1.to', output: '127.0.0.1.to' },
  { input: '[::1]', output: '[::1]' },
  { input: 'example.com.', output: 'example.com.' },
  { input: 'example..com', output: 'example..com' },
  { input: '.example.com', output: '.example.com' },
  { input: '**.example.com', output: '**.example.com' },
  { input: 'foo.**.example.com', output: 'foo.**.example.com' },
];

describe('domainToASCII()', () => {
  context('IDNA examples', () => {
    for (let example of idnaExamples) {
      it(`should encode ${example}`, () => {
        let result = domainToASCII(example);
        assert.equal(result, url.domainToASCII(example));
        assert.notEqual(result, '');
      });
    }
  });

  context('Public suffix list', () => {
    let content = readFileSync('tests/data/public_suffix_list.dat', 'utf8');
    let entries = content.split('\n')
                  .map(line => line.trim())
                  .map(line => line.replace(/\s*\/\/.*/, ''))
                  .filter(line => line !== '');
    for (let entry of entries) {
      it(`should encode ${entry}`, () => {
        let result = domainToASCII(entry);
        assert.equal(result, url.domainToASCII(entry));
        assert.notEqual(result, '');
      });
    }
  });

  context('Invalid inputs', () => {
    for (let input of invalidInputs) {
      it(`should not encode '${input}'`, () => {
        let result = domainToASCII(input);
        assert.equal(result, url.domainToASCII(input));
        assert.equal(result, '');
      });
    }
  });

  context('Special cases', () => {
    for (let { input, output } of specialCases) {
      it(`should encode '${input}' to '${output}'`, () => {
        let result = domainToASCII(input);
        assert.equal(result, url.domainToASCII(input));
        assert.equal(result, output);
      });
    }
  });

  // Differs from url.domainToASCII()
  context('Quirks', () => {
    it(`encodes 'example.com:8080' to 'example.com'`, () => {
      assert.equal(domainToASCII('example.com:8080'), 'example.com');
    });

    it(`encodes 'foo@example.com:8080' to 'example.com'`, () => {
      assert.equal(domainToASCII('foo@example.com:8080'), 'example.com');
    });

    it(`encodes 'https://foo@example.com:8080' to 'https.com'`, () => {
      // !
      assert.equal(domainToASCII('https://foo@example.com:8080'), 'https.com');
    });

    it(`encodes '/foo' to 'foo'`, () => {
      assert.equal(domainToASCII('/foo'), 'foo');
    });
  });
});
