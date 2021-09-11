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
  'افغانستا.icom.museum',
  'الجزائر.icom.museum',
  'österreich.icom.museum',
  'বাংলাদেশ.icom.museum',
  'беларусь.icom.museum',
  'belgië.icom.museum',
  'българия.icom.museum',
  'تشادر.icom.museum',
  '中国.icom.museum',
  'القمر.icom.museum',
  'κυπρος.icom.museum',
  'českárepublika.icom.museum',
  'مصر.icom.museum',
  'ελλάδα.icom.museum',
  'magyarország.icom.museum',
  'ísland.icom.museum',
  'भारत.icom.museum',
  'ايران.icom.museum',
  'éire.icom.museum',
  'איקו״ם.ישראל.museum',
  '日本.icom.museum',
  'الأردن.icom.museum',
  'қазақстан.icom.museum',
  '한국.icom.museum',
  'кыргызстан.icom.museum',
  'ລາວ.icom.museum',
  'لبنان.icom.museum',
  'македонија.icom.museum',
  'موريتانيا.icom.museum',
  'méxico.icom.museum',
  'монголулс.icom.museum',
  'المغرب.icom.museum',
  'नेपाल.icom.museum',
  'عمان.icom.museum',
  'قطر.icom.museum',
  'românia.icom.museum',
  'россия.иком.museum',
  'србијаицрнагора.иком.museum',
  'இலங்கை.icom.museum',
  'españa.icom.museum',
  'ไทย.icom.museum',
  'تونس.icom.museum',
  'türkiye.icom.museum',
  'украина.icom.museum',
  'việtnam.icom.museum',

  // https://xn--i-7iq.ws/
  'i❤️.ws',

  // https://unicode.org/reports/tr46/#IDNA2003-Section
  'Bücher.de',
  'bücher.de',
  'Buecher.de',
  'buecher.de',

  // https://unicode.org/reports/tr46/#IDNA2008-Section
  'ÖBB.at',
  'öbb.at',
  'OEBB.at',
  'oebb.at',

  // https://www.unicode.org/reports/tr46/#Deviations
  'faß.de',
  'βόλος.com',
  'ශ්‍රී.com',
  'نامه‌ای.com',

  // https://unicode.org/reports/tr46/#Compatibility_Processing
  '√.com',
];

let invalidInputs = [
  '',
  'e x a m p l e',
  '/foo',
  '?foo',
  'example.com:8080',
  'foo@example.com:8080',
  'https://foo@example.com:8080',
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
  { input: 'a\x7Fb', output: 'a\x7Fb' },
  { input: 'a\x7F', output: 'a\x7F' },
  { input: '\x7Fb', output: '\x7Fb' },
  { input: '\x7F', output: '\x7F' },
];

let ip4Addresses = [
  '0',
  '1',
  '2',
  '0.0',
  '1.1',
  '0.0.0',
  '256',
  '256.255',
  '16843009',
  '2147483647',
  '2147483648',
  '0.0.0.0',
  '0.0.0.0.0',
];

let ip6Addresses = [
  '[0:0:0:0:0:0:0:0]',
  '[0:0:0:0:0:0:0:1]',
  '[::1]',
  '[::]',
  '[:::]',
  '[:]',
  '[]',
  '[0:0:0:0:0:0:0:0:0]',
];

let combiningMarks = [
  '\u{0300}a',
  'a\u{0300}',
];

// https://datatracker.ietf.org/doc/html/rfc3490#section-3.1
let rfc3490Separators = [
  'www\u{3002}i\u{2764}.ws',
  'www\u{FF0E}i\u{2764}.ws',
  'www\u{FF61}i\u{2764}.ws',
];

let std3ASCII = [
  // disallowed_STD3_valid
  '≠',

  // disallowed_STD3_mapped
  '①',
  '⑴',

  '⁉',
];

describe('domainToASCII()', () => {
  let domainToASCII = null;

  before(async () => {
    let name = '../index.js';
    let module = await import(name);

    domainToASCII = module.domainToASCII;
  });

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
                  .map(line => line.replace(/^!/, ''))
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

  context('IPv4 addresses', () => {
    for (let address of ip4Addresses) {
      it(`should handle ${address} like Node.js`, () => {
        assert.equal(domainToASCII(address), url.domainToASCII(address));
      });
    }
  });

  context('IPv6 addresses', () => {
    for (let address of ip6Addresses) {
      it(`should handle ${address} like Node.js`, () => {
        assert.equal(domainToASCII(address), url.domainToASCII(address));
      });
    }
  });

  context('Combining marks', () => {
    for (let label of combiningMarks) {
      it(`should handle ${label} like Node.js`, () => {
        assert.equal(domainToASCII(label), url.domainToASCII(label));
      });
    }
  });

  context('RFC 3490 separators', () => {
    for (let domain of rfc3490Separators) {
      it(`should handle ${domain} like Node.js`, () => {
        assert.equal(domainToASCII(domain), url.domainToASCII(domain));
      });
    }
  });

  context('STD3 ASCII', () => {
    for (let label of std3ASCII) {
      it(`should handle ${label} like Node.js`, () => {
        assert.equal(domainToASCII(label), url.domainToASCII(label));
      });
    }
  });
});
