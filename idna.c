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

#include <stdint.h>

int idna_disallow(uint32_t cp) {
  return (
    (cp >= 0x0000 && cp <= 0x002C) ||
    cp == 0x002F ||
    (cp >= 0x003A && cp <= 0x0040) ||
    (cp >= 0x005B && cp <= 0x0060) ||
    (cp >= 0x007B && cp <= 0x007F) ||
    (cp >= 0x0080 && cp <= 0x009F) ||
    cp == 0x00A0 ||
    cp == 0x00A8 ||
    cp == 0x00AF ||
    cp == 0x00B4 ||
    cp == 0x00B8 ||
    cp == 0x02D8 ||
    cp == 0x02D9 ||
    cp == 0x02DA ||
    cp == 0x02DB ||
    cp == 0x02DC ||
    cp == 0x02DD ||
    (cp >= 0x0378 && cp <= 0x0379) ||
    cp == 0x037A ||
    cp == 0x037E ||
    (cp >= 0x0380 && cp <= 0x0383) ||
    cp == 0x0384 ||
    cp == 0x0385 ||
    cp == 0x038B ||
    cp == 0x038D ||
    cp == 0x03A2 ||
    cp == 0x04C0 ||
    cp == 0x0530 ||
    (cp >= 0x0557 && cp <= 0x0558) ||
    (cp >= 0x058B && cp <= 0x058C) ||
    cp == 0x0590 ||
    (cp >= 0x05C8 && cp <= 0x05CF) ||
    (cp >= 0x05EB && cp <= 0x05EE) ||
    (cp >= 0x05F5 && cp <= 0x05FF) ||
    (cp >= 0x0600 && cp <= 0x0603) ||
    cp == 0x0604 ||
    cp == 0x0605 ||
    cp == 0x061C ||
    cp == 0x06DD ||
    cp == 0x070E ||
    cp == 0x070F ||
    (cp >= 0x074B && cp <= 0x074C) ||
    (cp >= 0x07B2 && cp <= 0x07BF) ||
    (cp >= 0x07FB && cp <= 0x07FC) ||
    (cp >= 0x082E && cp <= 0x082F) ||
    cp == 0x083F ||
    (cp >= 0x085C && cp <= 0x085D) ||
    cp == 0x085F ||
    (cp >= 0x086B && cp <= 0x086F) ||
    cp == 0x088F ||
    (cp >= 0x0890 && cp <= 0x0891) ||
    (cp >= 0x0892 && cp <= 0x0897) ||
    cp == 0x08E2 ||
    cp == 0x0984 ||
    (cp >= 0x098D && cp <= 0x098E) ||
    (cp >= 0x0991 && cp <= 0x0992) ||
    cp == 0x09A9 ||
    cp == 0x09B1 ||
    (cp >= 0x09B3 && cp <= 0x09B5) ||
    (cp >= 0x09BA && cp <= 0x09BB) ||
    (cp >= 0x09C5 && cp <= 0x09C6) ||
    (cp >= 0x09C9 && cp <= 0x09CA) ||
    (cp >= 0x09CF && cp <= 0x09D6) ||
    (cp >= 0x09D8 && cp <= 0x09DB) ||
    cp == 0x09DE ||
    (cp >= 0x09E4 && cp <= 0x09E5) ||
    (cp >= 0x09FF && cp <= 0x0A00) ||
    cp == 0x0A04 ||
    (cp >= 0x0A0B && cp <= 0x0A0E) ||
    (cp >= 0x0A11 && cp <= 0x0A12) ||
    cp == 0x0A29 ||
    cp == 0x0A31 ||
    cp == 0x0A34 ||
    cp == 0x0A37 ||
    (cp >= 0x0A3A && cp <= 0x0A3B) ||
    cp == 0x0A3D ||
    (cp >= 0x0A43 && cp <= 0x0A46) ||
    (cp >= 0x0A49 && cp <= 0x0A4A) ||
    (cp >= 0x0A4E && cp <= 0x0A50) ||
    (cp >= 0x0A52 && cp <= 0x0A58) ||
    cp == 0x0A5D ||
    (cp >= 0x0A5F && cp <= 0x0A65) ||
    (cp >= 0x0A77 && cp <= 0x0A80) ||
    cp == 0x0A84 ||
    cp == 0x0A8E ||
    cp == 0x0A92 ||
    cp == 0x0AA9 ||
    cp == 0x0AB1 ||
    cp == 0x0AB4 ||
    (cp >= 0x0ABA && cp <= 0x0ABB) ||
    cp == 0x0AC6 ||
    cp == 0x0ACA ||
    (cp >= 0x0ACE && cp <= 0x0ACF) ||
    (cp >= 0x0AD1 && cp <= 0x0ADF) ||
    (cp >= 0x0AE4 && cp <= 0x0AE5) ||
    (cp >= 0x0AF2 && cp <= 0x0AF8) ||
    cp == 0x0B00 ||
    cp == 0x0B04 ||
    (cp >= 0x0B0D && cp <= 0x0B0E) ||
    (cp >= 0x0B11 && cp <= 0x0B12) ||
    cp == 0x0B29 ||
    cp == 0x0B31 ||
    cp == 0x0B34 ||
    (cp >= 0x0B3A && cp <= 0x0B3B) ||
    (cp >= 0x0B45 && cp <= 0x0B46) ||
    (cp >= 0x0B49 && cp <= 0x0B4A) ||
    (cp >= 0x0B4E && cp <= 0x0B54) ||
    (cp >= 0x0B58 && cp <= 0x0B5B) ||
    cp == 0x0B5E ||
    (cp >= 0x0B64 && cp <= 0x0B65) ||
    (cp >= 0x0B78 && cp <= 0x0B81) ||
    cp == 0x0B84 ||
    (cp >= 0x0B8B && cp <= 0x0B8D) ||
    cp == 0x0B91 ||
    (cp >= 0x0B96 && cp <= 0x0B98) ||
    cp == 0x0B9B ||
    cp == 0x0B9D ||
    (cp >= 0x0BA0 && cp <= 0x0BA2) ||
    (cp >= 0x0BA5 && cp <= 0x0BA7) ||
    (cp >= 0x0BAB && cp <= 0x0BAD) ||
    (cp >= 0x0BBA && cp <= 0x0BBD) ||
    (cp >= 0x0BC3 && cp <= 0x0BC5) ||
    cp == 0x0BC9 ||
    (cp >= 0x0BCE && cp <= 0x0BCF) ||
    (cp >= 0x0BD1 && cp <= 0x0BD6) ||
    (cp >= 0x0BD8 && cp <= 0x0BE5) ||
    (cp >= 0x0BFB && cp <= 0x0BFF) ||
    cp == 0x0C0D ||
    cp == 0x0C11 ||
    cp == 0x0C29 ||
    (cp >= 0x0C3A && cp <= 0x0C3B) ||
    cp == 0x0C45 ||
    cp == 0x0C49 ||
    (cp >= 0x0C4E && cp <= 0x0C54) ||
    cp == 0x0C57 ||
    (cp >= 0x0C5B && cp <= 0x0C5C) ||
    (cp >= 0x0C5E && cp <= 0x0C5F) ||
    (cp >= 0x0C64 && cp <= 0x0C65) ||
    (cp >= 0x0C70 && cp <= 0x0C76) ||
    cp == 0x0C8D ||
    cp == 0x0C91 ||
    cp == 0x0CA9 ||
    cp == 0x0CB4 ||
    (cp >= 0x0CBA && cp <= 0x0CBB) ||
    cp == 0x0CC5 ||
    cp == 0x0CC9 ||
    (cp >= 0x0CCE && cp <= 0x0CD4) ||
    (cp >= 0x0CD7 && cp <= 0x0CDC) ||
    cp == 0x0CDF ||
    (cp >= 0x0CE4 && cp <= 0x0CE5) ||
    cp == 0x0CF0 ||
    (cp >= 0x0CF3 && cp <= 0x0CFF) ||
    cp == 0x0D0D ||
    cp == 0x0D11 ||
    cp == 0x0D45 ||
    cp == 0x0D49 ||
    (cp >= 0x0D50 && cp <= 0x0D53) ||
    (cp >= 0x0D64 && cp <= 0x0D65) ||
    cp == 0x0D80 ||
    cp == 0x0D84 ||
    (cp >= 0x0D97 && cp <= 0x0D99) ||
    cp == 0x0DB2 ||
    cp == 0x0DBC ||
    (cp >= 0x0DBE && cp <= 0x0DBF) ||
    (cp >= 0x0DC7 && cp <= 0x0DC9) ||
    (cp >= 0x0DCB && cp <= 0x0DCE) ||
    cp == 0x0DD5 ||
    cp == 0x0DD7 ||
    (cp >= 0x0DE0 && cp <= 0x0DE5) ||
    (cp >= 0x0DF0 && cp <= 0x0DF1) ||
    (cp >= 0x0DF5 && cp <= 0x0E00) ||
    (cp >= 0x0E3B && cp <= 0x0E3E) ||
    (cp >= 0x0E5C && cp <= 0x0E80) ||
    cp == 0x0E83 ||
    cp == 0x0E85 ||
    cp == 0x0E8B ||
    cp == 0x0EA4 ||
    cp == 0x0EA6 ||
    (cp >= 0x0EBE && cp <= 0x0EBF) ||
    cp == 0x0EC5 ||
    cp == 0x0EC7 ||
    (cp >= 0x0ECE && cp <= 0x0ECF) ||
    (cp >= 0x0EDA && cp <= 0x0EDB) ||
    (cp >= 0x0EE0 && cp <= 0x0EFF) ||
    cp == 0x0F48 ||
    (cp >= 0x0F6D && cp <= 0x0F70) ||
    cp == 0x0F98 ||
    cp == 0x0FBD ||
    cp == 0x0FCD ||
    (cp >= 0x0FDB && cp <= 0x0FFF) ||
    (cp >= 0x10A0 && cp <= 0x10C5) ||
    cp == 0x10C6 ||
    (cp >= 0x10C8 && cp <= 0x10CC) ||
    (cp >= 0x10CE && cp <= 0x10CF) ||
    (cp >= 0x115F && cp <= 0x1160) ||
    cp == 0x1249 ||
    (cp >= 0x124E && cp <= 0x124F) ||
    cp == 0x1257 ||
    cp == 0x1259 ||
    (cp >= 0x125E && cp <= 0x125F) ||
    cp == 0x1289 ||
    (cp >= 0x128E && cp <= 0x128F) ||
    cp == 0x12B1 ||
    (cp >= 0x12B6 && cp <= 0x12B7) ||
    cp == 0x12BF ||
    cp == 0x12C1 ||
    (cp >= 0x12C6 && cp <= 0x12C7) ||
    cp == 0x12D7 ||
    cp == 0x1311 ||
    (cp >= 0x1316 && cp <= 0x1317) ||
    (cp >= 0x135B && cp <= 0x135C) ||
    (cp >= 0x137D && cp <= 0x137F) ||
    (cp >= 0x139A && cp <= 0x139F) ||
    (cp >= 0x13F6 && cp <= 0x13F7) ||
    (cp >= 0x13FE && cp <= 0x13FF) ||
    cp == 0x1680 ||
    (cp >= 0x169D && cp <= 0x169F) ||
    (cp >= 0x16F9 && cp <= 0x16FF) ||
    (cp >= 0x1716 && cp <= 0x171E) ||
    (cp >= 0x1737 && cp <= 0x173F) ||
    (cp >= 0x1754 && cp <= 0x175F) ||
    cp == 0x176D ||
    cp == 0x1771 ||
    (cp >= 0x1774 && cp <= 0x177F) ||
    (cp >= 0x17B4 && cp <= 0x17B5) ||
    (cp >= 0x17DE && cp <= 0x17DF) ||
    (cp >= 0x17EA && cp <= 0x17EF) ||
    (cp >= 0x17FA && cp <= 0x17FF) ||
    cp == 0x1806 ||
    cp == 0x180E ||
    (cp >= 0x181A && cp <= 0x181F) ||
    (cp >= 0x1879 && cp <= 0x187F) ||
    (cp >= 0x18AB && cp <= 0x18AF) ||
    (cp >= 0x18F6 && cp <= 0x18FF) ||
    cp == 0x191F ||
    (cp >= 0x192C && cp <= 0x192F) ||
    (cp >= 0x193C && cp <= 0x193F) ||
    (cp >= 0x1941 && cp <= 0x1943) ||
    (cp >= 0x196E && cp <= 0x196F) ||
    (cp >= 0x1975 && cp <= 0x197F) ||
    (cp >= 0x19AC && cp <= 0x19AF) ||
    (cp >= 0x19CA && cp <= 0x19CF) ||
    (cp >= 0x19DB && cp <= 0x19DD) ||
    (cp >= 0x1A1C && cp <= 0x1A1D) ||
    cp == 0x1A5F ||
    (cp >= 0x1A7D && cp <= 0x1A7E) ||
    (cp >= 0x1A8A && cp <= 0x1A8F) ||
    (cp >= 0x1A9A && cp <= 0x1A9F) ||
    (cp >= 0x1AAE && cp <= 0x1AAF) ||
    (cp >= 0x1ACF && cp <= 0x1AFF) ||
    (cp >= 0x1B4D && cp <= 0x1B4F) ||
    cp == 0x1B7F ||
    (cp >= 0x1BF4 && cp <= 0x1BFB) ||
    (cp >= 0x1C38 && cp <= 0x1C3A) ||
    (cp >= 0x1C4A && cp <= 0x1C4C) ||
    (cp >= 0x1C89 && cp <= 0x1C8F) ||
    (cp >= 0x1CBB && cp <= 0x1CBC) ||
    (cp >= 0x1CC8 && cp <= 0x1CCF) ||
    (cp >= 0x1CFB && cp <= 0x1CFF) ||
    (cp >= 0x1F16 && cp <= 0x1F17) ||
    (cp >= 0x1F1E && cp <= 0x1F1F) ||
    (cp >= 0x1F46 && cp <= 0x1F47) ||
    (cp >= 0x1F4E && cp <= 0x1F4F) ||
    cp == 0x1F58 ||
    cp == 0x1F5A ||
    cp == 0x1F5C ||
    cp == 0x1F5E ||
    (cp >= 0x1F7E && cp <= 0x1F7F) ||
    cp == 0x1FB5 ||
    cp == 0x1FBD ||
    cp == 0x1FBF ||
    cp == 0x1FC0 ||
    cp == 0x1FC1 ||
    cp == 0x1FC5 ||
    cp == 0x1FCD ||
    cp == 0x1FCE ||
    cp == 0x1FCF ||
    (cp >= 0x1FD4 && cp <= 0x1FD5) ||
    cp == 0x1FDC ||
    cp == 0x1FDD ||
    cp == 0x1FDE ||
    cp == 0x1FDF ||
    cp == 0x1FED ||
    cp == 0x1FEE ||
    cp == 0x1FEF ||
    (cp >= 0x1FF0 && cp <= 0x1FF1) ||
    cp == 0x1FF5 ||
    cp == 0x1FFD ||
    cp == 0x1FFE ||
    cp == 0x1FFF ||
    (cp >= 0x2000 && cp <= 0x200A) ||
    (cp >= 0x200E && cp <= 0x200F) ||
    cp == 0x2017 ||
    (cp >= 0x2024 && cp <= 0x2026) ||
    (cp >= 0x2028 && cp <= 0x202E) ||
    cp == 0x202F ||
    cp == 0x203C ||
    cp == 0x203E ||
    cp == 0x2047 ||
    cp == 0x2048 ||
    cp == 0x2049 ||
    cp == 0x205F ||
    (cp >= 0x2061 && cp <= 0x2063) ||
    cp == 0x2065 ||
    (cp >= 0x2066 && cp <= 0x2069) ||
    (cp >= 0x206A && cp <= 0x206F) ||
    (cp >= 0x2072 && cp <= 0x2073) ||
    cp == 0x207A ||
    cp == 0x207C ||
    cp == 0x207D ||
    cp == 0x207E ||
    cp == 0x208A ||
    cp == 0x208C ||
    cp == 0x208D ||
    cp == 0x208E ||
    cp == 0x208F ||
    (cp >= 0x209D && cp <= 0x209F) ||
    (cp >= 0x20C1 && cp <= 0x20CF) ||
    (cp >= 0x20F1 && cp <= 0x20FF) ||
    cp == 0x2100 ||
    cp == 0x2101 ||
    cp == 0x2105 ||
    cp == 0x2106 ||
    cp == 0x2132 ||
    cp == 0x2183 ||
    (cp >= 0x218C && cp <= 0x218F) ||
    cp == 0x2260 ||
    (cp >= 0x226E && cp <= 0x226F) ||
    (cp >= 0x2427 && cp <= 0x243F) ||
    (cp >= 0x244B && cp <= 0x245F) ||
    cp == 0x2474 ||
    cp == 0x2475 ||
    cp == 0x2476 ||
    cp == 0x2477 ||
    cp == 0x2478 ||
    cp == 0x2479 ||
    cp == 0x247A ||
    cp == 0x247B ||
    cp == 0x247C ||
    cp == 0x247D ||
    cp == 0x247E ||
    cp == 0x247F ||
    cp == 0x2480 ||
    cp == 0x2481 ||
    cp == 0x2482 ||
    cp == 0x2483 ||
    cp == 0x2484 ||
    cp == 0x2485 ||
    cp == 0x2486 ||
    cp == 0x2487 ||
    (cp >= 0x2488 && cp <= 0x249B) ||
    cp == 0x249C ||
    cp == 0x249D ||
    cp == 0x249E ||
    cp == 0x249F ||
    cp == 0x24A0 ||
    cp == 0x24A1 ||
    cp == 0x24A2 ||
    cp == 0x24A3 ||
    cp == 0x24A4 ||
    cp == 0x24A5 ||
    cp == 0x24A6 ||
    cp == 0x24A7 ||
    cp == 0x24A8 ||
    cp == 0x24A9 ||
    cp == 0x24AA ||
    cp == 0x24AB ||
    cp == 0x24AC ||
    cp == 0x24AD ||
    cp == 0x24AE ||
    cp == 0x24AF ||
    cp == 0x24B0 ||
    cp == 0x24B1 ||
    cp == 0x24B2 ||
    cp == 0x24B3 ||
    cp == 0x24B4 ||
    cp == 0x24B5 ||
    cp == 0x2A74 ||
    cp == 0x2A75 ||
    cp == 0x2A76 ||
    (cp >= 0x2B74 && cp <= 0x2B75) ||
    cp == 0x2B96 ||
    (cp >= 0x2CF4 && cp <= 0x2CF8) ||
    cp == 0x2D26 ||
    (cp >= 0x2D28 && cp <= 0x2D2C) ||
    (cp >= 0x2D2E && cp <= 0x2D2F) ||
    (cp >= 0x2D68 && cp <= 0x2D6E) ||
    (cp >= 0x2D71 && cp <= 0x2D7E) ||
    (cp >= 0x2D97 && cp <= 0x2D9F) ||
    cp == 0x2DA7 ||
    cp == 0x2DAF ||
    cp == 0x2DB7 ||
    cp == 0x2DBF ||
    cp == 0x2DC7 ||
    cp == 0x2DCF ||
    cp == 0x2DD7 ||
    cp == 0x2DDF ||
    (cp >= 0x2E5E && cp <= 0x2E7F) ||
    cp == 0x2E9A ||
    (cp >= 0x2EF4 && cp <= 0x2EFF) ||
    (cp >= 0x2FD6 && cp <= 0x2FEF) ||
    (cp >= 0x2FF0 && cp <= 0x2FFB) ||
    (cp >= 0x2FFC && cp <= 0x2FFF) ||
    cp == 0x3000 ||
    cp == 0x3040 ||
    (cp >= 0x3097 && cp <= 0x3098) ||
    cp == 0x309B ||
    cp == 0x309C ||
    (cp >= 0x3100 && cp <= 0x3104) ||
    cp == 0x3130 ||
    cp == 0x3164 ||
    cp == 0x318F ||
    (cp >= 0x31E4 && cp <= 0x31EF) ||
    cp == 0x3200 ||
    cp == 0x3201 ||
    cp == 0x3202 ||
    cp == 0x3203 ||
    cp == 0x3204 ||
    cp == 0x3205 ||
    cp == 0x3206 ||
    cp == 0x3207 ||
    cp == 0x3208 ||
    cp == 0x3209 ||
    cp == 0x320A ||
    cp == 0x320B ||
    cp == 0x320C ||
    cp == 0x320D ||
    cp == 0x320E ||
    cp == 0x320F ||
    cp == 0x3210 ||
    cp == 0x3211 ||
    cp == 0x3212 ||
    cp == 0x3213 ||
    cp == 0x3214 ||
    cp == 0x3215 ||
    cp == 0x3216 ||
    cp == 0x3217 ||
    cp == 0x3218 ||
    cp == 0x3219 ||
    cp == 0x321A ||
    cp == 0x321B ||
    cp == 0x321C ||
    cp == 0x321D ||
    cp == 0x321E ||
    cp == 0x321F ||
    cp == 0x3220 ||
    cp == 0x3221 ||
    cp == 0x3222 ||
    cp == 0x3223 ||
    cp == 0x3224 ||
    cp == 0x3225 ||
    cp == 0x3226 ||
    cp == 0x3227 ||
    cp == 0x3228 ||
    cp == 0x3229 ||
    cp == 0x322A ||
    cp == 0x322B ||
    cp == 0x322C ||
    cp == 0x322D ||
    cp == 0x322E ||
    cp == 0x322F ||
    cp == 0x3230 ||
    cp == 0x3231 ||
    cp == 0x3232 ||
    cp == 0x3233 ||
    cp == 0x3234 ||
    cp == 0x3235 ||
    cp == 0x3236 ||
    cp == 0x3237 ||
    cp == 0x3238 ||
    cp == 0x3239 ||
    cp == 0x323A ||
    cp == 0x323B ||
    cp == 0x323C ||
    cp == 0x323D ||
    cp == 0x323E ||
    cp == 0x323F ||
    cp == 0x3240 ||
    cp == 0x3241 ||
    cp == 0x3242 ||
    cp == 0x3243 ||
    cp == 0x33C2 ||
    cp == 0x33C7 ||
    cp == 0x33D8 ||
    (cp >= 0xA48D && cp <= 0xA48F) ||
    (cp >= 0xA4C7 && cp <= 0xA4CF) ||
    (cp >= 0xA62C && cp <= 0xA63F) ||
    (cp >= 0xA6F8 && cp <= 0xA6FF) ||
    (cp >= 0xA7CB && cp <= 0xA7CF) ||
    cp == 0xA7D2 ||
    cp == 0xA7D4 ||
    (cp >= 0xA7DA && cp <= 0xA7F1) ||
    (cp >= 0xA82D && cp <= 0xA82F) ||
    (cp >= 0xA83A && cp <= 0xA83F) ||
    (cp >= 0xA878 && cp <= 0xA87F) ||
    (cp >= 0xA8C6 && cp <= 0xA8CD) ||
    (cp >= 0xA8DA && cp <= 0xA8DF) ||
    (cp >= 0xA954 && cp <= 0xA95E) ||
    (cp >= 0xA97D && cp <= 0xA97F) ||
    cp == 0xA9CE ||
    (cp >= 0xA9DA && cp <= 0xA9DD) ||
    cp == 0xA9FF ||
    (cp >= 0xAA37 && cp <= 0xAA3F) ||
    (cp >= 0xAA4E && cp <= 0xAA4F) ||
    (cp >= 0xAA5A && cp <= 0xAA5B) ||
    (cp >= 0xAAC3 && cp <= 0xAADA) ||
    (cp >= 0xAAF7 && cp <= 0xAB00) ||
    (cp >= 0xAB07 && cp <= 0xAB08) ||
    (cp >= 0xAB0F && cp <= 0xAB10) ||
    (cp >= 0xAB17 && cp <= 0xAB1F) ||
    cp == 0xAB27 ||
    cp == 0xAB2F ||
    (cp >= 0xAB6C && cp <= 0xAB6F) ||
    (cp >= 0xABEE && cp <= 0xABEF) ||
    (cp >= 0xABFA && cp <= 0xABFF) ||
    (cp >= 0xD7A4 && cp <= 0xD7AF) ||
    (cp >= 0xD7C7 && cp <= 0xD7CA) ||
    (cp >= 0xD7FC && cp <= 0xD7FF) ||
    (cp >= 0xD800 && cp <= 0xDFFF) ||
    (cp >= 0xE000 && cp <= 0xF8FF) ||
    (cp >= 0xFA6E && cp <= 0xFA6F) ||
    (cp >= 0xFADA && cp <= 0xFAFF) ||
    (cp >= 0xFB07 && cp <= 0xFB12) ||
    (cp >= 0xFB18 && cp <= 0xFB1C) ||
    cp == 0xFB29 ||
    cp == 0xFB37 ||
    cp == 0xFB3D ||
    cp == 0xFB3F ||
    cp == 0xFB42 ||
    cp == 0xFB45 ||
    (cp >= 0xFBC3 && cp <= 0xFBD2) ||
    cp == 0xFC5E ||
    cp == 0xFC5F ||
    cp == 0xFC60 ||
    cp == 0xFC61 ||
    cp == 0xFC62 ||
    cp == 0xFC63 ||
    (cp >= 0xFD90 && cp <= 0xFD91) ||
    (cp >= 0xFDC8 && cp <= 0xFDCE) ||
    (cp >= 0xFDD0 && cp <= 0xFDEF) ||
    cp == 0xFDFA ||
    cp == 0xFDFB ||
    cp == 0xFE10 ||
    cp == 0xFE12 ||
    cp == 0xFE13 ||
    cp == 0xFE14 ||
    cp == 0xFE15 ||
    cp == 0xFE16 ||
    cp == 0xFE19 ||
    (cp >= 0xFE1A && cp <= 0xFE1F) ||
    cp == 0xFE30 ||
    (cp >= 0xFE33 && cp <= 0xFE34) ||
    cp == 0xFE35 ||
    cp == 0xFE36 ||
    cp == 0xFE37 ||
    cp == 0xFE38 ||
    cp == 0xFE47 ||
    cp == 0xFE48 ||
    (cp >= 0xFE49 && cp <= 0xFE4C) ||
    (cp >= 0xFE4D && cp <= 0xFE4F) ||
    cp == 0xFE50 ||
    cp == 0xFE52 ||
    cp == 0xFE53 ||
    cp == 0xFE54 ||
    cp == 0xFE55 ||
    cp == 0xFE56 ||
    cp == 0xFE57 ||
    cp == 0xFE59 ||
    cp == 0xFE5A ||
    cp == 0xFE5B ||
    cp == 0xFE5C ||
    cp == 0xFE5F ||
    cp == 0xFE60 ||
    cp == 0xFE61 ||
    cp == 0xFE62 ||
    cp == 0xFE64 ||
    cp == 0xFE65 ||
    cp == 0xFE66 ||
    cp == 0xFE67 ||
    cp == 0xFE68 ||
    cp == 0xFE69 ||
    cp == 0xFE6A ||
    cp == 0xFE6B ||
    (cp >= 0xFE6C && cp <= 0xFE6F) ||
    cp == 0xFE70 ||
    cp == 0xFE72 ||
    cp == 0xFE74 ||
    cp == 0xFE75 ||
    cp == 0xFE76 ||
    cp == 0xFE78 ||
    cp == 0xFE7A ||
    cp == 0xFE7C ||
    cp == 0xFE7E ||
    (cp >= 0xFEFD && cp <= 0xFEFE) ||
    cp == 0xFF00 ||
    cp == 0xFF01 ||
    cp == 0xFF02 ||
    cp == 0xFF03 ||
    cp == 0xFF04 ||
    cp == 0xFF05 ||
    cp == 0xFF06 ||
    cp == 0xFF07 ||
    cp == 0xFF08 ||
    cp == 0xFF09 ||
    cp == 0xFF0A ||
    cp == 0xFF0B ||
    cp == 0xFF0C ||
    cp == 0xFF0F ||
    cp == 0xFF1A ||
    cp == 0xFF1B ||
    cp == 0xFF1C ||
    cp == 0xFF1D ||
    cp == 0xFF1E ||
    cp == 0xFF1F ||
    cp == 0xFF20 ||
    cp == 0xFF3B ||
    cp == 0xFF3C ||
    cp == 0xFF3D ||
    cp == 0xFF3E ||
    cp == 0xFF3F ||
    cp == 0xFF40 ||
    cp == 0xFF5B ||
    cp == 0xFF5C ||
    cp == 0xFF5D ||
    cp == 0xFF5E ||
    cp == 0xFFA0 ||
    (cp >= 0xFFBF && cp <= 0xFFC1) ||
    (cp >= 0xFFC8 && cp <= 0xFFC9) ||
    (cp >= 0xFFD0 && cp <= 0xFFD1) ||
    (cp >= 0xFFD8 && cp <= 0xFFD9) ||
    (cp >= 0xFFDD && cp <= 0xFFDF) ||
    cp == 0xFFE3 ||
    cp == 0xFFE7 ||
    (cp >= 0xFFEF && cp <= 0xFFF8) ||
    (cp >= 0xFFF9 && cp <= 0xFFFB) ||
    cp == 0xFFFC ||
    cp == 0xFFFD ||
    (cp >= 0xFFFE && cp <= 0xFFFF) ||
    cp == 0x1000C ||
    cp == 0x10027 ||
    cp == 0x1003B ||
    cp == 0x1003E ||
    (cp >= 0x1004E && cp <= 0x1004F) ||
    (cp >= 0x1005E && cp <= 0x1007F) ||
    (cp >= 0x100FB && cp <= 0x100FF) ||
    (cp >= 0x10103 && cp <= 0x10106) ||
    (cp >= 0x10134 && cp <= 0x10136) ||
    cp == 0x1018F ||
    (cp >= 0x1019D && cp <= 0x1019F) ||
    (cp >= 0x101A1 && cp <= 0x101CF) ||
    (cp >= 0x101FE && cp <= 0x1027F) ||
    (cp >= 0x1029D && cp <= 0x1029F) ||
    (cp >= 0x102D1 && cp <= 0x102DF) ||
    (cp >= 0x102FC && cp <= 0x102FF) ||
    (cp >= 0x10324 && cp <= 0x1032C) ||
    (cp >= 0x1034B && cp <= 0x1034F) ||
    (cp >= 0x1037B && cp <= 0x1037F) ||
    cp == 0x1039E ||
    (cp >= 0x103C4 && cp <= 0x103C7) ||
    (cp >= 0x103D6 && cp <= 0x103FF) ||
    (cp >= 0x1049E && cp <= 0x1049F) ||
    (cp >= 0x104AA && cp <= 0x104AF) ||
    (cp >= 0x104D4 && cp <= 0x104D7) ||
    (cp >= 0x104FC && cp <= 0x104FF) ||
    (cp >= 0x10528 && cp <= 0x1052F) ||
    (cp >= 0x10564 && cp <= 0x1056E) ||
    cp == 0x1057B ||
    cp == 0x1058B ||
    cp == 0x10593 ||
    cp == 0x10596 ||
    cp == 0x105A2 ||
    cp == 0x105B2 ||
    cp == 0x105BA ||
    (cp >= 0x105BD && cp <= 0x105FF) ||
    (cp >= 0x10737 && cp <= 0x1073F) ||
    (cp >= 0x10756 && cp <= 0x1075F) ||
    (cp >= 0x10768 && cp <= 0x1077F) ||
    cp == 0x10786 ||
    cp == 0x107B1 ||
    (cp >= 0x107BB && cp <= 0x107FF) ||
    (cp >= 0x10806 && cp <= 0x10807) ||
    cp == 0x10809 ||
    cp == 0x10836 ||
    (cp >= 0x10839 && cp <= 0x1083B) ||
    (cp >= 0x1083D && cp <= 0x1083E) ||
    cp == 0x10856 ||
    (cp >= 0x1089F && cp <= 0x108A6) ||
    (cp >= 0x108B0 && cp <= 0x108DF) ||
    cp == 0x108F3 ||
    (cp >= 0x108F6 && cp <= 0x108FA) ||
    (cp >= 0x1091C && cp <= 0x1091E) ||
    (cp >= 0x1093A && cp <= 0x1093E) ||
    (cp >= 0x10940 && cp <= 0x1097F) ||
    (cp >= 0x109B8 && cp <= 0x109BB) ||
    (cp >= 0x109D0 && cp <= 0x109D1) ||
    cp == 0x10A04 ||
    (cp >= 0x10A07 && cp <= 0x10A0B) ||
    cp == 0x10A14 ||
    cp == 0x10A18 ||
    (cp >= 0x10A36 && cp <= 0x10A37) ||
    (cp >= 0x10A3B && cp <= 0x10A3E) ||
    (cp >= 0x10A49 && cp <= 0x10A4F) ||
    (cp >= 0x10A59 && cp <= 0x10A5F) ||
    (cp >= 0x10AA0 && cp <= 0x10ABF) ||
    (cp >= 0x10AE7 && cp <= 0x10AEA) ||
    (cp >= 0x10AF7 && cp <= 0x10AFF) ||
    (cp >= 0x10B36 && cp <= 0x10B38) ||
    (cp >= 0x10B56 && cp <= 0x10B57) ||
    (cp >= 0x10B73 && cp <= 0x10B77) ||
    (cp >= 0x10B92 && cp <= 0x10B98) ||
    (cp >= 0x10B9D && cp <= 0x10BA8) ||
    (cp >= 0x10BB0 && cp <= 0x10BFF) ||
    (cp >= 0x10C49 && cp <= 0x10C7F) ||
    (cp >= 0x10CB3 && cp <= 0x10CBF) ||
    (cp >= 0x10CF3 && cp <= 0x10CF9) ||
    (cp >= 0x10D28 && cp <= 0x10D2F) ||
    (cp >= 0x10D3A && cp <= 0x10E5F) ||
    cp == 0x10E7F ||
    cp == 0x10EAA ||
    (cp >= 0x10EAE && cp <= 0x10EAF) ||
    (cp >= 0x10EB2 && cp <= 0x10EFF) ||
    (cp >= 0x10F28 && cp <= 0x10F2F) ||
    (cp >= 0x10F5A && cp <= 0x10F6F) ||
    (cp >= 0x10F8A && cp <= 0x10FAF) ||
    (cp >= 0x10FCC && cp <= 0x10FDF) ||
    (cp >= 0x10FF7 && cp <= 0x10FFF) ||
    (cp >= 0x1104E && cp <= 0x11051) ||
    (cp >= 0x11076 && cp <= 0x1107E) ||
    cp == 0x110BD ||
    (cp >= 0x110C3 && cp <= 0x110CC) ||
    cp == 0x110CD ||
    (cp >= 0x110CE && cp <= 0x110CF) ||
    (cp >= 0x110E9 && cp <= 0x110EF) ||
    (cp >= 0x110FA && cp <= 0x110FF) ||
    cp == 0x11135 ||
    (cp >= 0x11148 && cp <= 0x1114F) ||
    (cp >= 0x11177 && cp <= 0x1117F) ||
    cp == 0x111E0 ||
    (cp >= 0x111F5 && cp <= 0x111FF) ||
    cp == 0x11212 ||
    (cp >= 0x1123F && cp <= 0x1127F) ||
    cp == 0x11287 ||
    cp == 0x11289 ||
    cp == 0x1128E ||
    cp == 0x1129E ||
    (cp >= 0x112AA && cp <= 0x112AF) ||
    (cp >= 0x112EB && cp <= 0x112EF) ||
    (cp >= 0x112FA && cp <= 0x112FF) ||
    cp == 0x11304 ||
    (cp >= 0x1130D && cp <= 0x1130E) ||
    (cp >= 0x11311 && cp <= 0x11312) ||
    cp == 0x11329 ||
    cp == 0x11331 ||
    cp == 0x11334 ||
    cp == 0x1133A ||
    (cp >= 0x11345 && cp <= 0x11346) ||
    (cp >= 0x11349 && cp <= 0x1134A) ||
    (cp >= 0x1134E && cp <= 0x1134F) ||
    (cp >= 0x11351 && cp <= 0x11356) ||
    (cp >= 0x11358 && cp <= 0x1135C) ||
    (cp >= 0x11364 && cp <= 0x11365) ||
    (cp >= 0x1136D && cp <= 0x1136F) ||
    (cp >= 0x11375 && cp <= 0x113FF) ||
    cp == 0x1145C ||
    (cp >= 0x11462 && cp <= 0x1147F) ||
    (cp >= 0x114C8 && cp <= 0x114CF) ||
    (cp >= 0x114DA && cp <= 0x1157F) ||
    (cp >= 0x115B6 && cp <= 0x115B7) ||
    (cp >= 0x115DE && cp <= 0x115FF) ||
    (cp >= 0x11645 && cp <= 0x1164F) ||
    (cp >= 0x1165A && cp <= 0x1165F) ||
    (cp >= 0x1166D && cp <= 0x1167F) ||
    (cp >= 0x116BA && cp <= 0x116BF) ||
    (cp >= 0x116CA && cp <= 0x116FF) ||
    (cp >= 0x1171B && cp <= 0x1171C) ||
    (cp >= 0x1172C && cp <= 0x1172F) ||
    (cp >= 0x11747 && cp <= 0x117FF) ||
    (cp >= 0x1183C && cp <= 0x1189F) ||
    (cp >= 0x118F3 && cp <= 0x118FE) ||
    (cp >= 0x11907 && cp <= 0x11908) ||
    (cp >= 0x1190A && cp <= 0x1190B) ||
    cp == 0x11914 ||
    cp == 0x11917 ||
    cp == 0x11936 ||
    (cp >= 0x11939 && cp <= 0x1193A) ||
    (cp >= 0x11947 && cp <= 0x1194F) ||
    (cp >= 0x1195A && cp <= 0x1199F) ||
    (cp >= 0x119A8 && cp <= 0x119A9) ||
    (cp >= 0x119D8 && cp <= 0x119D9) ||
    (cp >= 0x119E5 && cp <= 0x119FF) ||
    (cp >= 0x11A48 && cp <= 0x11A4F) ||
    (cp >= 0x11AA3 && cp <= 0x11AAF) ||
    (cp >= 0x11AF9 && cp <= 0x11BFF) ||
    cp == 0x11C09 ||
    cp == 0x11C37 ||
    (cp >= 0x11C46 && cp <= 0x11C4F) ||
    (cp >= 0x11C6D && cp <= 0x11C6F) ||
    (cp >= 0x11C90 && cp <= 0x11C91) ||
    cp == 0x11CA8 ||
    (cp >= 0x11CB7 && cp <= 0x11CFF) ||
    cp == 0x11D07 ||
    cp == 0x11D0A ||
    (cp >= 0x11D37 && cp <= 0x11D39) ||
    cp == 0x11D3B ||
    cp == 0x11D3E ||
    (cp >= 0x11D48 && cp <= 0x11D4F) ||
    (cp >= 0x11D5A && cp <= 0x11D5F) ||
    cp == 0x11D66 ||
    cp == 0x11D69 ||
    cp == 0x11D8F ||
    cp == 0x11D92 ||
    (cp >= 0x11D99 && cp <= 0x11D9F) ||
    (cp >= 0x11DAA && cp <= 0x11EDF) ||
    (cp >= 0x11EF9 && cp <= 0x11FAF) ||
    (cp >= 0x11FB1 && cp <= 0x11FBF) ||
    (cp >= 0x11FF2 && cp <= 0x11FFE) ||
    (cp >= 0x1239A && cp <= 0x123FF) ||
    cp == 0x1246F ||
    (cp >= 0x12475 && cp <= 0x1247F) ||
    (cp >= 0x12544 && cp <= 0x12F8F) ||
    (cp >= 0x12FF3 && cp <= 0x12FFF) ||
    cp == 0x1342F ||
    (cp >= 0x13430 && cp <= 0x13438) ||
    (cp >= 0x13439 && cp <= 0x143FF) ||
    (cp >= 0x14647 && cp <= 0x167FF) ||
    (cp >= 0x16A39 && cp <= 0x16A3F) ||
    cp == 0x16A5F ||
    (cp >= 0x16A6A && cp <= 0x16A6D) ||
    cp == 0x16ABF ||
    (cp >= 0x16ACA && cp <= 0x16ACF) ||
    (cp >= 0x16AEE && cp <= 0x16AEF) ||
    (cp >= 0x16AF6 && cp <= 0x16AFF) ||
    (cp >= 0x16B46 && cp <= 0x16B4F) ||
    cp == 0x16B5A ||
    cp == 0x16B62 ||
    (cp >= 0x16B78 && cp <= 0x16B7C) ||
    (cp >= 0x16B90 && cp <= 0x16E3F) ||
    (cp >= 0x16E9B && cp <= 0x16EFF) ||
    (cp >= 0x16F4B && cp <= 0x16F4E) ||
    (cp >= 0x16F88 && cp <= 0x16F8E) ||
    (cp >= 0x16FA0 && cp <= 0x16FDF) ||
    (cp >= 0x16FE5 && cp <= 0x16FEF) ||
    (cp >= 0x16FF2 && cp <= 0x16FFF) ||
    (cp >= 0x187F8 && cp <= 0x187FF) ||
    (cp >= 0x18CD6 && cp <= 0x18CFF) ||
    (cp >= 0x18D09 && cp <= 0x1AFEF) ||
    cp == 0x1AFF4 ||
    cp == 0x1AFFC ||
    cp == 0x1AFFF ||
    (cp >= 0x1B123 && cp <= 0x1B14F) ||
    (cp >= 0x1B153 && cp <= 0x1B163) ||
    (cp >= 0x1B168 && cp <= 0x1B16F) ||
    (cp >= 0x1B2FC && cp <= 0x1BBFF) ||
    (cp >= 0x1BC6B && cp <= 0x1BC6F) ||
    (cp >= 0x1BC7D && cp <= 0x1BC7F) ||
    (cp >= 0x1BC89 && cp <= 0x1BC8F) ||
    (cp >= 0x1BC9A && cp <= 0x1BC9B) ||
    (cp >= 0x1BCA4 && cp <= 0x1CEFF) ||
    (cp >= 0x1CF2E && cp <= 0x1CF2F) ||
    (cp >= 0x1CF47 && cp <= 0x1CF4F) ||
    (cp >= 0x1CFC4 && cp <= 0x1CFFF) ||
    (cp >= 0x1D0F6 && cp <= 0x1D0FF) ||
    (cp >= 0x1D127 && cp <= 0x1D128) ||
    (cp >= 0x1D173 && cp <= 0x1D17A) ||
    (cp >= 0x1D1EB && cp <= 0x1D1FF) ||
    (cp >= 0x1D246 && cp <= 0x1D2DF) ||
    (cp >= 0x1D2F4 && cp <= 0x1D2FF) ||
    (cp >= 0x1D357 && cp <= 0x1D35F) ||
    (cp >= 0x1D379 && cp <= 0x1D3FF) ||
    cp == 0x1D455 ||
    cp == 0x1D49D ||
    (cp >= 0x1D4A0 && cp <= 0x1D4A1) ||
    (cp >= 0x1D4A3 && cp <= 0x1D4A4) ||
    (cp >= 0x1D4A7 && cp <= 0x1D4A8) ||
    cp == 0x1D4AD ||
    cp == 0x1D4BA ||
    cp == 0x1D4BC ||
    cp == 0x1D4C4 ||
    cp == 0x1D506 ||
    (cp >= 0x1D50B && cp <= 0x1D50C) ||
    cp == 0x1D515 ||
    cp == 0x1D51D ||
    cp == 0x1D53A ||
    cp == 0x1D53F ||
    cp == 0x1D545 ||
    (cp >= 0x1D547 && cp <= 0x1D549) ||
    cp == 0x1D551 ||
    (cp >= 0x1D6A6 && cp <= 0x1D6A7) ||
    (cp >= 0x1D7CC && cp <= 0x1D7CD) ||
    (cp >= 0x1DA8C && cp <= 0x1DA9A) ||
    cp == 0x1DAA0 ||
    (cp >= 0x1DAB0 && cp <= 0x1DEFF) ||
    (cp >= 0x1DF1F && cp <= 0x1DFFF) ||
    cp == 0x1E007 ||
    (cp >= 0x1E019 && cp <= 0x1E01A) ||
    cp == 0x1E022 ||
    cp == 0x1E025 ||
    (cp >= 0x1E02B && cp <= 0x1E0FF) ||
    (cp >= 0x1E12D && cp <= 0x1E12F) ||
    (cp >= 0x1E13E && cp <= 0x1E13F) ||
    (cp >= 0x1E14A && cp <= 0x1E14D) ||
    (cp >= 0x1E150 && cp <= 0x1E28F) ||
    (cp >= 0x1E2AF && cp <= 0x1E2BF) ||
    (cp >= 0x1E2FA && cp <= 0x1E2FE) ||
    (cp >= 0x1E300 && cp <= 0x1E7DF) ||
    cp == 0x1E7E7 ||
    cp == 0x1E7EC ||
    cp == 0x1E7EF ||
    cp == 0x1E7FF ||
    (cp >= 0x1E8C5 && cp <= 0x1E8C6) ||
    (cp >= 0x1E8D7 && cp <= 0x1E8FF) ||
    (cp >= 0x1E94C && cp <= 0x1E94F) ||
    (cp >= 0x1E95A && cp <= 0x1E95D) ||
    (cp >= 0x1E960 && cp <= 0x1EC70) ||
    (cp >= 0x1ECB5 && cp <= 0x1ED00) ||
    (cp >= 0x1ED3E && cp <= 0x1EDFF) ||
    cp == 0x1EE04 ||
    cp == 0x1EE20 ||
    cp == 0x1EE23 ||
    (cp >= 0x1EE25 && cp <= 0x1EE26) ||
    cp == 0x1EE28 ||
    cp == 0x1EE33 ||
    cp == 0x1EE38 ||
    cp == 0x1EE3A ||
    (cp >= 0x1EE3C && cp <= 0x1EE41) ||
    (cp >= 0x1EE43 && cp <= 0x1EE46) ||
    cp == 0x1EE48 ||
    cp == 0x1EE4A ||
    cp == 0x1EE4C ||
    cp == 0x1EE50 ||
    cp == 0x1EE53 ||
    (cp >= 0x1EE55 && cp <= 0x1EE56) ||
    cp == 0x1EE58 ||
    cp == 0x1EE5A ||
    cp == 0x1EE5C ||
    cp == 0x1EE5E ||
    cp == 0x1EE60 ||
    cp == 0x1EE63 ||
    (cp >= 0x1EE65 && cp <= 0x1EE66) ||
    cp == 0x1EE6B ||
    cp == 0x1EE73 ||
    cp == 0x1EE78 ||
    cp == 0x1EE7D ||
    cp == 0x1EE7F ||
    cp == 0x1EE8A ||
    (cp >= 0x1EE9C && cp <= 0x1EEA0) ||
    cp == 0x1EEA4 ||
    cp == 0x1EEAA ||
    (cp >= 0x1EEBC && cp <= 0x1EEEF) ||
    (cp >= 0x1EEF2 && cp <= 0x1EFFF) ||
    (cp >= 0x1F02C && cp <= 0x1F02F) ||
    (cp >= 0x1F094 && cp <= 0x1F09F) ||
    (cp >= 0x1F0AF && cp <= 0x1F0B0) ||
    cp == 0x1F0C0 ||
    cp == 0x1F0D0 ||
    (cp >= 0x1F0F6 && cp <= 0x1F0FF) ||
    cp == 0x1F100 ||
    cp == 0x1F101 ||
    cp == 0x1F102 ||
    cp == 0x1F103 ||
    cp == 0x1F104 ||
    cp == 0x1F105 ||
    cp == 0x1F106 ||
    cp == 0x1F107 ||
    cp == 0x1F108 ||
    cp == 0x1F109 ||
    cp == 0x1F10A ||
    cp == 0x1F110 ||
    cp == 0x1F111 ||
    cp == 0x1F112 ||
    cp == 0x1F113 ||
    cp == 0x1F114 ||
    cp == 0x1F115 ||
    cp == 0x1F116 ||
    cp == 0x1F117 ||
    cp == 0x1F118 ||
    cp == 0x1F119 ||
    cp == 0x1F11A ||
    cp == 0x1F11B ||
    cp == 0x1F11C ||
    cp == 0x1F11D ||
    cp == 0x1F11E ||
    cp == 0x1F11F ||
    cp == 0x1F120 ||
    cp == 0x1F121 ||
    cp == 0x1F122 ||
    cp == 0x1F123 ||
    cp == 0x1F124 ||
    cp == 0x1F125 ||
    cp == 0x1F126 ||
    cp == 0x1F127 ||
    cp == 0x1F128 ||
    cp == 0x1F129 ||
    (cp >= 0x1F1AE && cp <= 0x1F1E5) ||
    (cp >= 0x1F203 && cp <= 0x1F20F) ||
    (cp >= 0x1F23C && cp <= 0x1F23F) ||
    (cp >= 0x1F249 && cp <= 0x1F24F) ||
    (cp >= 0x1F252 && cp <= 0x1F25F) ||
    (cp >= 0x1F266 && cp <= 0x1F2FF) ||
    (cp >= 0x1F6D8 && cp <= 0x1F6DC) ||
    (cp >= 0x1F6ED && cp <= 0x1F6EF) ||
    (cp >= 0x1F6FD && cp <= 0x1F6FF) ||
    (cp >= 0x1F774 && cp <= 0x1F77F) ||
    (cp >= 0x1F7D9 && cp <= 0x1F7DF) ||
    (cp >= 0x1F7EC && cp <= 0x1F7EF) ||
    (cp >= 0x1F7F1 && cp <= 0x1F7FF) ||
    (cp >= 0x1F80C && cp <= 0x1F80F) ||
    (cp >= 0x1F848 && cp <= 0x1F84F) ||
    (cp >= 0x1F85A && cp <= 0x1F85F) ||
    (cp >= 0x1F888 && cp <= 0x1F88F) ||
    (cp >= 0x1F8AE && cp <= 0x1F8AF) ||
    (cp >= 0x1F8B2 && cp <= 0x1F8FF) ||
    (cp >= 0x1FA54 && cp <= 0x1FA5F) ||
    (cp >= 0x1FA6E && cp <= 0x1FA6F) ||
    (cp >= 0x1FA75 && cp <= 0x1FA77) ||
    (cp >= 0x1FA7D && cp <= 0x1FA7F) ||
    (cp >= 0x1FA87 && cp <= 0x1FA8F) ||
    (cp >= 0x1FAAD && cp <= 0x1FAAF) ||
    (cp >= 0x1FABB && cp <= 0x1FABF) ||
    (cp >= 0x1FAC6 && cp <= 0x1FACF) ||
    (cp >= 0x1FADA && cp <= 0x1FADF) ||
    (cp >= 0x1FAE8 && cp <= 0x1FAEF) ||
    (cp >= 0x1FAF7 && cp <= 0x1FAFF) ||
    cp == 0x1FB93 ||
    (cp >= 0x1FBCB && cp <= 0x1FBEF) ||
    (cp >= 0x1FBFA && cp <= 0x1FFFD) ||
    (cp >= 0x1FFFE && cp <= 0x1FFFF) ||
    (cp >= 0x2A6E0 && cp <= 0x2A6FF) ||
    (cp >= 0x2B739 && cp <= 0x2B73F) ||
    (cp >= 0x2B81E && cp <= 0x2B81F) ||
    (cp >= 0x2CEA2 && cp <= 0x2CEAF) ||
    (cp >= 0x2EBE1 && cp <= 0x2F7FF) ||
    cp == 0x2F868 ||
    cp == 0x2F874 ||
    cp == 0x2F91F ||
    cp == 0x2F95F ||
    cp == 0x2F9BF ||
    (cp >= 0x2FA1E && cp <= 0x2FFFD) ||
    (cp >= 0x2FFFE && cp <= 0x2FFFF) ||
    (cp >= 0x3134B && cp <= 0x3FFFD) ||
    (cp >= 0x3FFFE && cp <= 0x3FFFF) ||
    (cp >= 0x40000 && cp <= 0x4FFFD) ||
    (cp >= 0x4FFFE && cp <= 0x4FFFF) ||
    (cp >= 0x50000 && cp <= 0x5FFFD) ||
    (cp >= 0x5FFFE && cp <= 0x5FFFF) ||
    (cp >= 0x60000 && cp <= 0x6FFFD) ||
    (cp >= 0x6FFFE && cp <= 0x6FFFF) ||
    (cp >= 0x70000 && cp <= 0x7FFFD) ||
    (cp >= 0x7FFFE && cp <= 0x7FFFF) ||
    (cp >= 0x80000 && cp <= 0x8FFFD) ||
    (cp >= 0x8FFFE && cp <= 0x8FFFF) ||
    (cp >= 0x90000 && cp <= 0x9FFFD) ||
    (cp >= 0x9FFFE && cp <= 0x9FFFF) ||
    (cp >= 0xA0000 && cp <= 0xAFFFD) ||
    (cp >= 0xAFFFE && cp <= 0xAFFFF) ||
    (cp >= 0xB0000 && cp <= 0xBFFFD) ||
    (cp >= 0xBFFFE && cp <= 0xBFFFF) ||
    (cp >= 0xC0000 && cp <= 0xCFFFD) ||
    (cp >= 0xCFFFE && cp <= 0xCFFFF) ||
    (cp >= 0xD0000 && cp <= 0xDFFFD) ||
    (cp >= 0xDFFFE && cp <= 0xDFFFF) ||
    cp == 0xE0000 ||
    cp == 0xE0001 ||
    (cp >= 0xE0002 && cp <= 0xE001F) ||
    (cp >= 0xE0020 && cp <= 0xE007F) ||
    (cp >= 0xE0080 && cp <= 0xE00FF) ||
    (cp >= 0xE01F0 && cp <= 0xEFFFD) ||
    (cp >= 0xEFFFE && cp <= 0xEFFFF) ||
    (cp >= 0xF0000 && cp <= 0xFFFFD) ||
    (cp >= 0xFFFFE && cp <= 0xFFFFF) ||
    (cp >= 0x100000 && cp <= 0x10FFFD) ||
    (cp >= 0x10FFFE && cp <= 0x10FFFF)
  );
}
