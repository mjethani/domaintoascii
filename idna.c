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

static uint32_t disallowed[][2] = {
  { 0x0000, 0x002C },
  { 0x002F, 0x002F },
  { 0x003A, 0x0040 },
  { 0x005B, 0x0060 },
  { 0x007B, 0x007F },
  { 0x0080, 0x009F },
  { 0x00A0, 0x00A0 },
  { 0x00A8, 0x00A8 },
  { 0x00AF, 0x00AF },
  { 0x00B4, 0x00B4 },
  { 0x00B8, 0x00B8 },
  { 0x02D8, 0x02D8 },
  { 0x02D9, 0x02D9 },
  { 0x02DA, 0x02DA },
  { 0x02DB, 0x02DB },
  { 0x02DC, 0x02DC },
  { 0x02DD, 0x02DD },
  { 0x0378, 0x0379 },
  { 0x037A, 0x037A },
  { 0x037E, 0x037E },
  { 0x0380, 0x0383 },
  { 0x0384, 0x0384 },
  { 0x0385, 0x0385 },
  { 0x038B, 0x038B },
  { 0x038D, 0x038D },
  { 0x03A2, 0x03A2 },
  { 0x04C0, 0x04C0 },
  { 0x0530, 0x0530 },
  { 0x0557, 0x0558 },
  { 0x058B, 0x058C },
  { 0x0590, 0x0590 },
  { 0x05C8, 0x05CF },
  { 0x05EB, 0x05EE },
  { 0x05F5, 0x05FF },
  { 0x0600, 0x0603 },
  { 0x0604, 0x0604 },
  { 0x0605, 0x0605 },
  { 0x061C, 0x061C },
  { 0x06DD, 0x06DD },
  { 0x070E, 0x070E },
  { 0x070F, 0x070F },
  { 0x074B, 0x074C },
  { 0x07B2, 0x07BF },
  { 0x07FB, 0x07FC },
  { 0x082E, 0x082F },
  { 0x083F, 0x083F },
  { 0x085C, 0x085D },
  { 0x085F, 0x085F },
  { 0x086B, 0x086F },
  { 0x088F, 0x088F },
  { 0x0890, 0x0891 },
  { 0x0892, 0x0897 },
  { 0x08E2, 0x08E2 },
  { 0x0984, 0x0984 },
  { 0x098D, 0x098E },
  { 0x0991, 0x0992 },
  { 0x09A9, 0x09A9 },
  { 0x09B1, 0x09B1 },
  { 0x09B3, 0x09B5 },
  { 0x09BA, 0x09BB },
  { 0x09C5, 0x09C6 },
  { 0x09C9, 0x09CA },
  { 0x09CF, 0x09D6 },
  { 0x09D8, 0x09DB },
  { 0x09DE, 0x09DE },
  { 0x09E4, 0x09E5 },
  { 0x09FF, 0x0A00 },
  { 0x0A04, 0x0A04 },
  { 0x0A0B, 0x0A0E },
  { 0x0A11, 0x0A12 },
  { 0x0A29, 0x0A29 },
  { 0x0A31, 0x0A31 },
  { 0x0A34, 0x0A34 },
  { 0x0A37, 0x0A37 },
  { 0x0A3A, 0x0A3B },
  { 0x0A3D, 0x0A3D },
  { 0x0A43, 0x0A46 },
  { 0x0A49, 0x0A4A },
  { 0x0A4E, 0x0A50 },
  { 0x0A52, 0x0A58 },
  { 0x0A5D, 0x0A5D },
  { 0x0A5F, 0x0A65 },
  { 0x0A77, 0x0A80 },
  { 0x0A84, 0x0A84 },
  { 0x0A8E, 0x0A8E },
  { 0x0A92, 0x0A92 },
  { 0x0AA9, 0x0AA9 },
  { 0x0AB1, 0x0AB1 },
  { 0x0AB4, 0x0AB4 },
  { 0x0ABA, 0x0ABB },
  { 0x0AC6, 0x0AC6 },
  { 0x0ACA, 0x0ACA },
  { 0x0ACE, 0x0ACF },
  { 0x0AD1, 0x0ADF },
  { 0x0AE4, 0x0AE5 },
  { 0x0AF2, 0x0AF8 },
  { 0x0B00, 0x0B00 },
  { 0x0B04, 0x0B04 },
  { 0x0B0D, 0x0B0E },
  { 0x0B11, 0x0B12 },
  { 0x0B29, 0x0B29 },
  { 0x0B31, 0x0B31 },
  { 0x0B34, 0x0B34 },
  { 0x0B3A, 0x0B3B },
  { 0x0B45, 0x0B46 },
  { 0x0B49, 0x0B4A },
  { 0x0B4E, 0x0B54 },
  { 0x0B58, 0x0B5B },
  { 0x0B5E, 0x0B5E },
  { 0x0B64, 0x0B65 },
  { 0x0B78, 0x0B81 },
  { 0x0B84, 0x0B84 },
  { 0x0B8B, 0x0B8D },
  { 0x0B91, 0x0B91 },
  { 0x0B96, 0x0B98 },
  { 0x0B9B, 0x0B9B },
  { 0x0B9D, 0x0B9D },
  { 0x0BA0, 0x0BA2 },
  { 0x0BA5, 0x0BA7 },
  { 0x0BAB, 0x0BAD },
  { 0x0BBA, 0x0BBD },
  { 0x0BC3, 0x0BC5 },
  { 0x0BC9, 0x0BC9 },
  { 0x0BCE, 0x0BCF },
  { 0x0BD1, 0x0BD6 },
  { 0x0BD8, 0x0BE5 },
  { 0x0BFB, 0x0BFF },
  { 0x0C0D, 0x0C0D },
  { 0x0C11, 0x0C11 },
  { 0x0C29, 0x0C29 },
  { 0x0C3A, 0x0C3B },
  { 0x0C45, 0x0C45 },
  { 0x0C49, 0x0C49 },
  { 0x0C4E, 0x0C54 },
  { 0x0C57, 0x0C57 },
  { 0x0C5B, 0x0C5C },
  { 0x0C5E, 0x0C5F },
  { 0x0C64, 0x0C65 },
  { 0x0C70, 0x0C76 },
  { 0x0C8D, 0x0C8D },
  { 0x0C91, 0x0C91 },
  { 0x0CA9, 0x0CA9 },
  { 0x0CB4, 0x0CB4 },
  { 0x0CBA, 0x0CBB },
  { 0x0CC5, 0x0CC5 },
  { 0x0CC9, 0x0CC9 },
  { 0x0CCE, 0x0CD4 },
  { 0x0CD7, 0x0CDC },
  { 0x0CDF, 0x0CDF },
  { 0x0CE4, 0x0CE5 },
  { 0x0CF0, 0x0CF0 },
  { 0x0CF3, 0x0CFF },
  { 0x0D0D, 0x0D0D },
  { 0x0D11, 0x0D11 },
  { 0x0D45, 0x0D45 },
  { 0x0D49, 0x0D49 },
  { 0x0D50, 0x0D53 },
  { 0x0D64, 0x0D65 },
  { 0x0D80, 0x0D80 },
  { 0x0D84, 0x0D84 },
  { 0x0D97, 0x0D99 },
  { 0x0DB2, 0x0DB2 },
  { 0x0DBC, 0x0DBC },
  { 0x0DBE, 0x0DBF },
  { 0x0DC7, 0x0DC9 },
  { 0x0DCB, 0x0DCE },
  { 0x0DD5, 0x0DD5 },
  { 0x0DD7, 0x0DD7 },
  { 0x0DE0, 0x0DE5 },
  { 0x0DF0, 0x0DF1 },
  { 0x0DF5, 0x0E00 },
  { 0x0E3B, 0x0E3E },
  { 0x0E5C, 0x0E80 },
  { 0x0E83, 0x0E83 },
  { 0x0E85, 0x0E85 },
  { 0x0E8B, 0x0E8B },
  { 0x0EA4, 0x0EA4 },
  { 0x0EA6, 0x0EA6 },
  { 0x0EBE, 0x0EBF },
  { 0x0EC5, 0x0EC5 },
  { 0x0EC7, 0x0EC7 },
  { 0x0ECE, 0x0ECF },
  { 0x0EDA, 0x0EDB },
  { 0x0EE0, 0x0EFF },
  { 0x0F48, 0x0F48 },
  { 0x0F6D, 0x0F70 },
  { 0x0F98, 0x0F98 },
  { 0x0FBD, 0x0FBD },
  { 0x0FCD, 0x0FCD },
  { 0x0FDB, 0x0FFF },
  { 0x10A0, 0x10C5 },
  { 0x10C6, 0x10C6 },
  { 0x10C8, 0x10CC },
  { 0x10CE, 0x10CF },
  { 0x115F, 0x1160 },
  { 0x1249, 0x1249 },
  { 0x124E, 0x124F },
  { 0x1257, 0x1257 },
  { 0x1259, 0x1259 },
  { 0x125E, 0x125F },
  { 0x1289, 0x1289 },
  { 0x128E, 0x128F },
  { 0x12B1, 0x12B1 },
  { 0x12B6, 0x12B7 },
  { 0x12BF, 0x12BF },
  { 0x12C1, 0x12C1 },
  { 0x12C6, 0x12C7 },
  { 0x12D7, 0x12D7 },
  { 0x1311, 0x1311 },
  { 0x1316, 0x1317 },
  { 0x135B, 0x135C },
  { 0x137D, 0x137F },
  { 0x139A, 0x139F },
  { 0x13F6, 0x13F7 },
  { 0x13FE, 0x13FF },
  { 0x1680, 0x1680 },
  { 0x169D, 0x169F },
  { 0x16F9, 0x16FF },
  { 0x1716, 0x171E },
  { 0x1737, 0x173F },
  { 0x1754, 0x175F },
  { 0x176D, 0x176D },
  { 0x1771, 0x1771 },
  { 0x1774, 0x177F },
  { 0x17B4, 0x17B5 },
  { 0x17DE, 0x17DF },
  { 0x17EA, 0x17EF },
  { 0x17FA, 0x17FF },
  { 0x1806, 0x1806 },
  { 0x180E, 0x180E },
  { 0x181A, 0x181F },
  { 0x1879, 0x187F },
  { 0x18AB, 0x18AF },
  { 0x18F6, 0x18FF },
  { 0x191F, 0x191F },
  { 0x192C, 0x192F },
  { 0x193C, 0x193F },
  { 0x1941, 0x1943 },
  { 0x196E, 0x196F },
  { 0x1975, 0x197F },
  { 0x19AC, 0x19AF },
  { 0x19CA, 0x19CF },
  { 0x19DB, 0x19DD },
  { 0x1A1C, 0x1A1D },
  { 0x1A5F, 0x1A5F },
  { 0x1A7D, 0x1A7E },
  { 0x1A8A, 0x1A8F },
  { 0x1A9A, 0x1A9F },
  { 0x1AAE, 0x1AAF },
  { 0x1ACF, 0x1AFF },
  { 0x1B4D, 0x1B4F },
  { 0x1B7F, 0x1B7F },
  { 0x1BF4, 0x1BFB },
  { 0x1C38, 0x1C3A },
  { 0x1C4A, 0x1C4C },
  { 0x1C89, 0x1C8F },
  { 0x1CBB, 0x1CBC },
  { 0x1CC8, 0x1CCF },
  { 0x1CFB, 0x1CFF },
  { 0x1F16, 0x1F17 },
  { 0x1F1E, 0x1F1F },
  { 0x1F46, 0x1F47 },
  { 0x1F4E, 0x1F4F },
  { 0x1F58, 0x1F58 },
  { 0x1F5A, 0x1F5A },
  { 0x1F5C, 0x1F5C },
  { 0x1F5E, 0x1F5E },
  { 0x1F7E, 0x1F7F },
  { 0x1FB5, 0x1FB5 },
  { 0x1FBD, 0x1FBD },
  { 0x1FBF, 0x1FBF },
  { 0x1FC0, 0x1FC0 },
  { 0x1FC1, 0x1FC1 },
  { 0x1FC5, 0x1FC5 },
  { 0x1FCD, 0x1FCD },
  { 0x1FCE, 0x1FCE },
  { 0x1FCF, 0x1FCF },
  { 0x1FD4, 0x1FD5 },
  { 0x1FDC, 0x1FDC },
  { 0x1FDD, 0x1FDD },
  { 0x1FDE, 0x1FDE },
  { 0x1FDF, 0x1FDF },
  { 0x1FED, 0x1FED },
  { 0x1FEE, 0x1FEE },
  { 0x1FEF, 0x1FEF },
  { 0x1FF0, 0x1FF1 },
  { 0x1FF5, 0x1FF5 },
  { 0x1FFD, 0x1FFD },
  { 0x1FFE, 0x1FFE },
  { 0x1FFF, 0x1FFF },
  { 0x2000, 0x200A },
  { 0x200E, 0x200F },
  { 0x2017, 0x2017 },
  { 0x2024, 0x2026 },
  { 0x2028, 0x202E },
  { 0x202F, 0x202F },
  { 0x203C, 0x203C },
  { 0x203E, 0x203E },
  { 0x2047, 0x2047 },
  { 0x2048, 0x2048 },
  { 0x2049, 0x2049 },
  { 0x205F, 0x205F },
  { 0x2061, 0x2063 },
  { 0x2065, 0x2065 },
  { 0x2066, 0x2069 },
  { 0x206A, 0x206F },
  { 0x2072, 0x2073 },
  { 0x207A, 0x207A },
  { 0x207C, 0x207C },
  { 0x207D, 0x207D },
  { 0x207E, 0x207E },
  { 0x208A, 0x208A },
  { 0x208C, 0x208C },
  { 0x208D, 0x208D },
  { 0x208E, 0x208E },
  { 0x208F, 0x208F },
  { 0x209D, 0x209F },
  { 0x20C1, 0x20CF },
  { 0x20F1, 0x20FF },
  { 0x2100, 0x2100 },
  { 0x2101, 0x2101 },
  { 0x2105, 0x2105 },
  { 0x2106, 0x2106 },
  { 0x2132, 0x2132 },
  { 0x2183, 0x2183 },
  { 0x218C, 0x218F },
  { 0x2260, 0x2260 },
  { 0x226E, 0x226F },
  { 0x2427, 0x243F },
  { 0x244B, 0x245F },
  { 0x2474, 0x2474 },
  { 0x2475, 0x2475 },
  { 0x2476, 0x2476 },
  { 0x2477, 0x2477 },
  { 0x2478, 0x2478 },
  { 0x2479, 0x2479 },
  { 0x247A, 0x247A },
  { 0x247B, 0x247B },
  { 0x247C, 0x247C },
  { 0x247D, 0x247D },
  { 0x247E, 0x247E },
  { 0x247F, 0x247F },
  { 0x2480, 0x2480 },
  { 0x2481, 0x2481 },
  { 0x2482, 0x2482 },
  { 0x2483, 0x2483 },
  { 0x2484, 0x2484 },
  { 0x2485, 0x2485 },
  { 0x2486, 0x2486 },
  { 0x2487, 0x2487 },
  { 0x2488, 0x249B },
  { 0x249C, 0x249C },
  { 0x249D, 0x249D },
  { 0x249E, 0x249E },
  { 0x249F, 0x249F },
  { 0x24A0, 0x24A0 },
  { 0x24A1, 0x24A1 },
  { 0x24A2, 0x24A2 },
  { 0x24A3, 0x24A3 },
  { 0x24A4, 0x24A4 },
  { 0x24A5, 0x24A5 },
  { 0x24A6, 0x24A6 },
  { 0x24A7, 0x24A7 },
  { 0x24A8, 0x24A8 },
  { 0x24A9, 0x24A9 },
  { 0x24AA, 0x24AA },
  { 0x24AB, 0x24AB },
  { 0x24AC, 0x24AC },
  { 0x24AD, 0x24AD },
  { 0x24AE, 0x24AE },
  { 0x24AF, 0x24AF },
  { 0x24B0, 0x24B0 },
  { 0x24B1, 0x24B1 },
  { 0x24B2, 0x24B2 },
  { 0x24B3, 0x24B3 },
  { 0x24B4, 0x24B4 },
  { 0x24B5, 0x24B5 },
  { 0x2A74, 0x2A74 },
  { 0x2A75, 0x2A75 },
  { 0x2A76, 0x2A76 },
  { 0x2B74, 0x2B75 },
  { 0x2B96, 0x2B96 },
  { 0x2CF4, 0x2CF8 },
  { 0x2D26, 0x2D26 },
  { 0x2D28, 0x2D2C },
  { 0x2D2E, 0x2D2F },
  { 0x2D68, 0x2D6E },
  { 0x2D71, 0x2D7E },
  { 0x2D97, 0x2D9F },
  { 0x2DA7, 0x2DA7 },
  { 0x2DAF, 0x2DAF },
  { 0x2DB7, 0x2DB7 },
  { 0x2DBF, 0x2DBF },
  { 0x2DC7, 0x2DC7 },
  { 0x2DCF, 0x2DCF },
  { 0x2DD7, 0x2DD7 },
  { 0x2DDF, 0x2DDF },
  { 0x2E5E, 0x2E7F },
  { 0x2E9A, 0x2E9A },
  { 0x2EF4, 0x2EFF },
  { 0x2FD6, 0x2FEF },
  { 0x2FF0, 0x2FFB },
  { 0x2FFC, 0x2FFF },
  { 0x3000, 0x3000 },
  { 0x3040, 0x3040 },
  { 0x3097, 0x3098 },
  { 0x309B, 0x309B },
  { 0x309C, 0x309C },
  { 0x3100, 0x3104 },
  { 0x3130, 0x3130 },
  { 0x3164, 0x3164 },
  { 0x318F, 0x318F },
  { 0x31E4, 0x31EF },
  { 0x3200, 0x3200 },
  { 0x3201, 0x3201 },
  { 0x3202, 0x3202 },
  { 0x3203, 0x3203 },
  { 0x3204, 0x3204 },
  { 0x3205, 0x3205 },
  { 0x3206, 0x3206 },
  { 0x3207, 0x3207 },
  { 0x3208, 0x3208 },
  { 0x3209, 0x3209 },
  { 0x320A, 0x320A },
  { 0x320B, 0x320B },
  { 0x320C, 0x320C },
  { 0x320D, 0x320D },
  { 0x320E, 0x320E },
  { 0x320F, 0x320F },
  { 0x3210, 0x3210 },
  { 0x3211, 0x3211 },
  { 0x3212, 0x3212 },
  { 0x3213, 0x3213 },
  { 0x3214, 0x3214 },
  { 0x3215, 0x3215 },
  { 0x3216, 0x3216 },
  { 0x3217, 0x3217 },
  { 0x3218, 0x3218 },
  { 0x3219, 0x3219 },
  { 0x321A, 0x321A },
  { 0x321B, 0x321B },
  { 0x321C, 0x321C },
  { 0x321D, 0x321D },
  { 0x321E, 0x321E },
  { 0x321F, 0x321F },
  { 0x3220, 0x3220 },
  { 0x3221, 0x3221 },
  { 0x3222, 0x3222 },
  { 0x3223, 0x3223 },
  { 0x3224, 0x3224 },
  { 0x3225, 0x3225 },
  { 0x3226, 0x3226 },
  { 0x3227, 0x3227 },
  { 0x3228, 0x3228 },
  { 0x3229, 0x3229 },
  { 0x322A, 0x322A },
  { 0x322B, 0x322B },
  { 0x322C, 0x322C },
  { 0x322D, 0x322D },
  { 0x322E, 0x322E },
  { 0x322F, 0x322F },
  { 0x3230, 0x3230 },
  { 0x3231, 0x3231 },
  { 0x3232, 0x3232 },
  { 0x3233, 0x3233 },
  { 0x3234, 0x3234 },
  { 0x3235, 0x3235 },
  { 0x3236, 0x3236 },
  { 0x3237, 0x3237 },
  { 0x3238, 0x3238 },
  { 0x3239, 0x3239 },
  { 0x323A, 0x323A },
  { 0x323B, 0x323B },
  { 0x323C, 0x323C },
  { 0x323D, 0x323D },
  { 0x323E, 0x323E },
  { 0x323F, 0x323F },
  { 0x3240, 0x3240 },
  { 0x3241, 0x3241 },
  { 0x3242, 0x3242 },
  { 0x3243, 0x3243 },
  { 0x33C2, 0x33C2 },
  { 0x33C7, 0x33C7 },
  { 0x33D8, 0x33D8 },
  { 0xA48D, 0xA48F },
  { 0xA4C7, 0xA4CF },
  { 0xA62C, 0xA63F },
  { 0xA6F8, 0xA6FF },
  { 0xA7CB, 0xA7CF },
  { 0xA7D2, 0xA7D2 },
  { 0xA7D4, 0xA7D4 },
  { 0xA7DA, 0xA7F1 },
  { 0xA82D, 0xA82F },
  { 0xA83A, 0xA83F },
  { 0xA878, 0xA87F },
  { 0xA8C6, 0xA8CD },
  { 0xA8DA, 0xA8DF },
  { 0xA954, 0xA95E },
  { 0xA97D, 0xA97F },
  { 0xA9CE, 0xA9CE },
  { 0xA9DA, 0xA9DD },
  { 0xA9FF, 0xA9FF },
  { 0xAA37, 0xAA3F },
  { 0xAA4E, 0xAA4F },
  { 0xAA5A, 0xAA5B },
  { 0xAAC3, 0xAADA },
  { 0xAAF7, 0xAB00 },
  { 0xAB07, 0xAB08 },
  { 0xAB0F, 0xAB10 },
  { 0xAB17, 0xAB1F },
  { 0xAB27, 0xAB27 },
  { 0xAB2F, 0xAB2F },
  { 0xAB6C, 0xAB6F },
  { 0xABEE, 0xABEF },
  { 0xABFA, 0xABFF },
  { 0xD7A4, 0xD7AF },
  { 0xD7C7, 0xD7CA },
  { 0xD7FC, 0xD7FF },
  { 0xD800, 0xDFFF },
  { 0xE000, 0xF8FF },
  { 0xFA6E, 0xFA6F },
  { 0xFADA, 0xFAFF },
  { 0xFB07, 0xFB12 },
  { 0xFB18, 0xFB1C },
  { 0xFB29, 0xFB29 },
  { 0xFB37, 0xFB37 },
  { 0xFB3D, 0xFB3D },
  { 0xFB3F, 0xFB3F },
  { 0xFB42, 0xFB42 },
  { 0xFB45, 0xFB45 },
  { 0xFBC3, 0xFBD2 },
  { 0xFC5E, 0xFC5E },
  { 0xFC5F, 0xFC5F },
  { 0xFC60, 0xFC60 },
  { 0xFC61, 0xFC61 },
  { 0xFC62, 0xFC62 },
  { 0xFC63, 0xFC63 },
  { 0xFD90, 0xFD91 },
  { 0xFDC8, 0xFDCE },
  { 0xFDD0, 0xFDEF },
  { 0xFDFA, 0xFDFA },
  { 0xFDFB, 0xFDFB },
  { 0xFE10, 0xFE10 },
  { 0xFE12, 0xFE12 },
  { 0xFE13, 0xFE13 },
  { 0xFE14, 0xFE14 },
  { 0xFE15, 0xFE15 },
  { 0xFE16, 0xFE16 },
  { 0xFE19, 0xFE19 },
  { 0xFE1A, 0xFE1F },
  { 0xFE30, 0xFE30 },
  { 0xFE33, 0xFE34 },
  { 0xFE35, 0xFE35 },
  { 0xFE36, 0xFE36 },
  { 0xFE37, 0xFE37 },
  { 0xFE38, 0xFE38 },
  { 0xFE47, 0xFE47 },
  { 0xFE48, 0xFE48 },
  { 0xFE49, 0xFE4C },
  { 0xFE4D, 0xFE4F },
  { 0xFE50, 0xFE50 },
  { 0xFE52, 0xFE52 },
  { 0xFE53, 0xFE53 },
  { 0xFE54, 0xFE54 },
  { 0xFE55, 0xFE55 },
  { 0xFE56, 0xFE56 },
  { 0xFE57, 0xFE57 },
  { 0xFE59, 0xFE59 },
  { 0xFE5A, 0xFE5A },
  { 0xFE5B, 0xFE5B },
  { 0xFE5C, 0xFE5C },
  { 0xFE5F, 0xFE5F },
  { 0xFE60, 0xFE60 },
  { 0xFE61, 0xFE61 },
  { 0xFE62, 0xFE62 },
  { 0xFE64, 0xFE64 },
  { 0xFE65, 0xFE65 },
  { 0xFE66, 0xFE66 },
  { 0xFE67, 0xFE67 },
  { 0xFE68, 0xFE68 },
  { 0xFE69, 0xFE69 },
  { 0xFE6A, 0xFE6A },
  { 0xFE6B, 0xFE6B },
  { 0xFE6C, 0xFE6F },
  { 0xFE70, 0xFE70 },
  { 0xFE72, 0xFE72 },
  { 0xFE74, 0xFE74 },
  { 0xFE75, 0xFE75 },
  { 0xFE76, 0xFE76 },
  { 0xFE78, 0xFE78 },
  { 0xFE7A, 0xFE7A },
  { 0xFE7C, 0xFE7C },
  { 0xFE7E, 0xFE7E },
  { 0xFEFD, 0xFEFE },
  { 0xFF00, 0xFF00 },
  { 0xFF01, 0xFF01 },
  { 0xFF02, 0xFF02 },
  { 0xFF03, 0xFF03 },
  { 0xFF04, 0xFF04 },
  { 0xFF05, 0xFF05 },
  { 0xFF06, 0xFF06 },
  { 0xFF07, 0xFF07 },
  { 0xFF08, 0xFF08 },
  { 0xFF09, 0xFF09 },
  { 0xFF0A, 0xFF0A },
  { 0xFF0B, 0xFF0B },
  { 0xFF0C, 0xFF0C },
  { 0xFF0F, 0xFF0F },
  { 0xFF1A, 0xFF1A },
  { 0xFF1B, 0xFF1B },
  { 0xFF1C, 0xFF1C },
  { 0xFF1D, 0xFF1D },
  { 0xFF1E, 0xFF1E },
  { 0xFF1F, 0xFF1F },
  { 0xFF20, 0xFF20 },
  { 0xFF3B, 0xFF3B },
  { 0xFF3C, 0xFF3C },
  { 0xFF3D, 0xFF3D },
  { 0xFF3E, 0xFF3E },
  { 0xFF3F, 0xFF3F },
  { 0xFF40, 0xFF40 },
  { 0xFF5B, 0xFF5B },
  { 0xFF5C, 0xFF5C },
  { 0xFF5D, 0xFF5D },
  { 0xFF5E, 0xFF5E },
  { 0xFFA0, 0xFFA0 },
  { 0xFFBF, 0xFFC1 },
  { 0xFFC8, 0xFFC9 },
  { 0xFFD0, 0xFFD1 },
  { 0xFFD8, 0xFFD9 },
  { 0xFFDD, 0xFFDF },
  { 0xFFE3, 0xFFE3 },
  { 0xFFE7, 0xFFE7 },
  { 0xFFEF, 0xFFF8 },
  { 0xFFF9, 0xFFFB },
  { 0xFFFC, 0xFFFC },
  { 0xFFFD, 0xFFFD },
  { 0xFFFE, 0xFFFF },
  { 0x1000C, 0x1000C },
  { 0x10027, 0x10027 },
  { 0x1003B, 0x1003B },
  { 0x1003E, 0x1003E },
  { 0x1004E, 0x1004F },
  { 0x1005E, 0x1007F },
  { 0x100FB, 0x100FF },
  { 0x10103, 0x10106 },
  { 0x10134, 0x10136 },
  { 0x1018F, 0x1018F },
  { 0x1019D, 0x1019F },
  { 0x101A1, 0x101CF },
  { 0x101FE, 0x1027F },
  { 0x1029D, 0x1029F },
  { 0x102D1, 0x102DF },
  { 0x102FC, 0x102FF },
  { 0x10324, 0x1032C },
  { 0x1034B, 0x1034F },
  { 0x1037B, 0x1037F },
  { 0x1039E, 0x1039E },
  { 0x103C4, 0x103C7 },
  { 0x103D6, 0x103FF },
  { 0x1049E, 0x1049F },
  { 0x104AA, 0x104AF },
  { 0x104D4, 0x104D7 },
  { 0x104FC, 0x104FF },
  { 0x10528, 0x1052F },
  { 0x10564, 0x1056E },
  { 0x1057B, 0x1057B },
  { 0x1058B, 0x1058B },
  { 0x10593, 0x10593 },
  { 0x10596, 0x10596 },
  { 0x105A2, 0x105A2 },
  { 0x105B2, 0x105B2 },
  { 0x105BA, 0x105BA },
  { 0x105BD, 0x105FF },
  { 0x10737, 0x1073F },
  { 0x10756, 0x1075F },
  { 0x10768, 0x1077F },
  { 0x10786, 0x10786 },
  { 0x107B1, 0x107B1 },
  { 0x107BB, 0x107FF },
  { 0x10806, 0x10807 },
  { 0x10809, 0x10809 },
  { 0x10836, 0x10836 },
  { 0x10839, 0x1083B },
  { 0x1083D, 0x1083E },
  { 0x10856, 0x10856 },
  { 0x1089F, 0x108A6 },
  { 0x108B0, 0x108DF },
  { 0x108F3, 0x108F3 },
  { 0x108F6, 0x108FA },
  { 0x1091C, 0x1091E },
  { 0x1093A, 0x1093E },
  { 0x10940, 0x1097F },
  { 0x109B8, 0x109BB },
  { 0x109D0, 0x109D1 },
  { 0x10A04, 0x10A04 },
  { 0x10A07, 0x10A0B },
  { 0x10A14, 0x10A14 },
  { 0x10A18, 0x10A18 },
  { 0x10A36, 0x10A37 },
  { 0x10A3B, 0x10A3E },
  { 0x10A49, 0x10A4F },
  { 0x10A59, 0x10A5F },
  { 0x10AA0, 0x10ABF },
  { 0x10AE7, 0x10AEA },
  { 0x10AF7, 0x10AFF },
  { 0x10B36, 0x10B38 },
  { 0x10B56, 0x10B57 },
  { 0x10B73, 0x10B77 },
  { 0x10B92, 0x10B98 },
  { 0x10B9D, 0x10BA8 },
  { 0x10BB0, 0x10BFF },
  { 0x10C49, 0x10C7F },
  { 0x10CB3, 0x10CBF },
  { 0x10CF3, 0x10CF9 },
  { 0x10D28, 0x10D2F },
  { 0x10D3A, 0x10E5F },
  { 0x10E7F, 0x10E7F },
  { 0x10EAA, 0x10EAA },
  { 0x10EAE, 0x10EAF },
  { 0x10EB2, 0x10EFF },
  { 0x10F28, 0x10F2F },
  { 0x10F5A, 0x10F6F },
  { 0x10F8A, 0x10FAF },
  { 0x10FCC, 0x10FDF },
  { 0x10FF7, 0x10FFF },
  { 0x1104E, 0x11051 },
  { 0x11076, 0x1107E },
  { 0x110BD, 0x110BD },
  { 0x110C3, 0x110CC },
  { 0x110CD, 0x110CD },
  { 0x110CE, 0x110CF },
  { 0x110E9, 0x110EF },
  { 0x110FA, 0x110FF },
  { 0x11135, 0x11135 },
  { 0x11148, 0x1114F },
  { 0x11177, 0x1117F },
  { 0x111E0, 0x111E0 },
  { 0x111F5, 0x111FF },
  { 0x11212, 0x11212 },
  { 0x1123F, 0x1127F },
  { 0x11287, 0x11287 },
  { 0x11289, 0x11289 },
  { 0x1128E, 0x1128E },
  { 0x1129E, 0x1129E },
  { 0x112AA, 0x112AF },
  { 0x112EB, 0x112EF },
  { 0x112FA, 0x112FF },
  { 0x11304, 0x11304 },
  { 0x1130D, 0x1130E },
  { 0x11311, 0x11312 },
  { 0x11329, 0x11329 },
  { 0x11331, 0x11331 },
  { 0x11334, 0x11334 },
  { 0x1133A, 0x1133A },
  { 0x11345, 0x11346 },
  { 0x11349, 0x1134A },
  { 0x1134E, 0x1134F },
  { 0x11351, 0x11356 },
  { 0x11358, 0x1135C },
  { 0x11364, 0x11365 },
  { 0x1136D, 0x1136F },
  { 0x11375, 0x113FF },
  { 0x1145C, 0x1145C },
  { 0x11462, 0x1147F },
  { 0x114C8, 0x114CF },
  { 0x114DA, 0x1157F },
  { 0x115B6, 0x115B7 },
  { 0x115DE, 0x115FF },
  { 0x11645, 0x1164F },
  { 0x1165A, 0x1165F },
  { 0x1166D, 0x1167F },
  { 0x116BA, 0x116BF },
  { 0x116CA, 0x116FF },
  { 0x1171B, 0x1171C },
  { 0x1172C, 0x1172F },
  { 0x11747, 0x117FF },
  { 0x1183C, 0x1189F },
  { 0x118F3, 0x118FE },
  { 0x11907, 0x11908 },
  { 0x1190A, 0x1190B },
  { 0x11914, 0x11914 },
  { 0x11917, 0x11917 },
  { 0x11936, 0x11936 },
  { 0x11939, 0x1193A },
  { 0x11947, 0x1194F },
  { 0x1195A, 0x1199F },
  { 0x119A8, 0x119A9 },
  { 0x119D8, 0x119D9 },
  { 0x119E5, 0x119FF },
  { 0x11A48, 0x11A4F },
  { 0x11AA3, 0x11AAF },
  { 0x11AF9, 0x11BFF },
  { 0x11C09, 0x11C09 },
  { 0x11C37, 0x11C37 },
  { 0x11C46, 0x11C4F },
  { 0x11C6D, 0x11C6F },
  { 0x11C90, 0x11C91 },
  { 0x11CA8, 0x11CA8 },
  { 0x11CB7, 0x11CFF },
  { 0x11D07, 0x11D07 },
  { 0x11D0A, 0x11D0A },
  { 0x11D37, 0x11D39 },
  { 0x11D3B, 0x11D3B },
  { 0x11D3E, 0x11D3E },
  { 0x11D48, 0x11D4F },
  { 0x11D5A, 0x11D5F },
  { 0x11D66, 0x11D66 },
  { 0x11D69, 0x11D69 },
  { 0x11D8F, 0x11D8F },
  { 0x11D92, 0x11D92 },
  { 0x11D99, 0x11D9F },
  { 0x11DAA, 0x11EDF },
  { 0x11EF9, 0x11FAF },
  { 0x11FB1, 0x11FBF },
  { 0x11FF2, 0x11FFE },
  { 0x1239A, 0x123FF },
  { 0x1246F, 0x1246F },
  { 0x12475, 0x1247F },
  { 0x12544, 0x12F8F },
  { 0x12FF3, 0x12FFF },
  { 0x1342F, 0x1342F },
  { 0x13430, 0x13438 },
  { 0x13439, 0x143FF },
  { 0x14647, 0x167FF },
  { 0x16A39, 0x16A3F },
  { 0x16A5F, 0x16A5F },
  { 0x16A6A, 0x16A6D },
  { 0x16ABF, 0x16ABF },
  { 0x16ACA, 0x16ACF },
  { 0x16AEE, 0x16AEF },
  { 0x16AF6, 0x16AFF },
  { 0x16B46, 0x16B4F },
  { 0x16B5A, 0x16B5A },
  { 0x16B62, 0x16B62 },
  { 0x16B78, 0x16B7C },
  { 0x16B90, 0x16E3F },
  { 0x16E9B, 0x16EFF },
  { 0x16F4B, 0x16F4E },
  { 0x16F88, 0x16F8E },
  { 0x16FA0, 0x16FDF },
  { 0x16FE5, 0x16FEF },
  { 0x16FF2, 0x16FFF },
  { 0x187F8, 0x187FF },
  { 0x18CD6, 0x18CFF },
  { 0x18D09, 0x1AFEF },
  { 0x1AFF4, 0x1AFF4 },
  { 0x1AFFC, 0x1AFFC },
  { 0x1AFFF, 0x1AFFF },
  { 0x1B123, 0x1B14F },
  { 0x1B153, 0x1B163 },
  { 0x1B168, 0x1B16F },
  { 0x1B2FC, 0x1BBFF },
  { 0x1BC6B, 0x1BC6F },
  { 0x1BC7D, 0x1BC7F },
  { 0x1BC89, 0x1BC8F },
  { 0x1BC9A, 0x1BC9B },
  { 0x1BCA4, 0x1CEFF },
  { 0x1CF2E, 0x1CF2F },
  { 0x1CF47, 0x1CF4F },
  { 0x1CFC4, 0x1CFFF },
  { 0x1D0F6, 0x1D0FF },
  { 0x1D127, 0x1D128 },
  { 0x1D173, 0x1D17A },
  { 0x1D1EB, 0x1D1FF },
  { 0x1D246, 0x1D2DF },
  { 0x1D2F4, 0x1D2FF },
  { 0x1D357, 0x1D35F },
  { 0x1D379, 0x1D3FF },
  { 0x1D455, 0x1D455 },
  { 0x1D49D, 0x1D49D },
  { 0x1D4A0, 0x1D4A1 },
  { 0x1D4A3, 0x1D4A4 },
  { 0x1D4A7, 0x1D4A8 },
  { 0x1D4AD, 0x1D4AD },
  { 0x1D4BA, 0x1D4BA },
  { 0x1D4BC, 0x1D4BC },
  { 0x1D4C4, 0x1D4C4 },
  { 0x1D506, 0x1D506 },
  { 0x1D50B, 0x1D50C },
  { 0x1D515, 0x1D515 },
  { 0x1D51D, 0x1D51D },
  { 0x1D53A, 0x1D53A },
  { 0x1D53F, 0x1D53F },
  { 0x1D545, 0x1D545 },
  { 0x1D547, 0x1D549 },
  { 0x1D551, 0x1D551 },
  { 0x1D6A6, 0x1D6A7 },
  { 0x1D7CC, 0x1D7CD },
  { 0x1DA8C, 0x1DA9A },
  { 0x1DAA0, 0x1DAA0 },
  { 0x1DAB0, 0x1DEFF },
  { 0x1DF1F, 0x1DFFF },
  { 0x1E007, 0x1E007 },
  { 0x1E019, 0x1E01A },
  { 0x1E022, 0x1E022 },
  { 0x1E025, 0x1E025 },
  { 0x1E02B, 0x1E0FF },
  { 0x1E12D, 0x1E12F },
  { 0x1E13E, 0x1E13F },
  { 0x1E14A, 0x1E14D },
  { 0x1E150, 0x1E28F },
  { 0x1E2AF, 0x1E2BF },
  { 0x1E2FA, 0x1E2FE },
  { 0x1E300, 0x1E7DF },
  { 0x1E7E7, 0x1E7E7 },
  { 0x1E7EC, 0x1E7EC },
  { 0x1E7EF, 0x1E7EF },
  { 0x1E7FF, 0x1E7FF },
  { 0x1E8C5, 0x1E8C6 },
  { 0x1E8D7, 0x1E8FF },
  { 0x1E94C, 0x1E94F },
  { 0x1E95A, 0x1E95D },
  { 0x1E960, 0x1EC70 },
  { 0x1ECB5, 0x1ED00 },
  { 0x1ED3E, 0x1EDFF },
  { 0x1EE04, 0x1EE04 },
  { 0x1EE20, 0x1EE20 },
  { 0x1EE23, 0x1EE23 },
  { 0x1EE25, 0x1EE26 },
  { 0x1EE28, 0x1EE28 },
  { 0x1EE33, 0x1EE33 },
  { 0x1EE38, 0x1EE38 },
  { 0x1EE3A, 0x1EE3A },
  { 0x1EE3C, 0x1EE41 },
  { 0x1EE43, 0x1EE46 },
  { 0x1EE48, 0x1EE48 },
  { 0x1EE4A, 0x1EE4A },
  { 0x1EE4C, 0x1EE4C },
  { 0x1EE50, 0x1EE50 },
  { 0x1EE53, 0x1EE53 },
  { 0x1EE55, 0x1EE56 },
  { 0x1EE58, 0x1EE58 },
  { 0x1EE5A, 0x1EE5A },
  { 0x1EE5C, 0x1EE5C },
  { 0x1EE5E, 0x1EE5E },
  { 0x1EE60, 0x1EE60 },
  { 0x1EE63, 0x1EE63 },
  { 0x1EE65, 0x1EE66 },
  { 0x1EE6B, 0x1EE6B },
  { 0x1EE73, 0x1EE73 },
  { 0x1EE78, 0x1EE78 },
  { 0x1EE7D, 0x1EE7D },
  { 0x1EE7F, 0x1EE7F },
  { 0x1EE8A, 0x1EE8A },
  { 0x1EE9C, 0x1EEA0 },
  { 0x1EEA4, 0x1EEA4 },
  { 0x1EEAA, 0x1EEAA },
  { 0x1EEBC, 0x1EEEF },
  { 0x1EEF2, 0x1EFFF },
  { 0x1F02C, 0x1F02F },
  { 0x1F094, 0x1F09F },
  { 0x1F0AF, 0x1F0B0 },
  { 0x1F0C0, 0x1F0C0 },
  { 0x1F0D0, 0x1F0D0 },
  { 0x1F0F6, 0x1F0FF },
  { 0x1F100, 0x1F100 },
  { 0x1F101, 0x1F101 },
  { 0x1F102, 0x1F102 },
  { 0x1F103, 0x1F103 },
  { 0x1F104, 0x1F104 },
  { 0x1F105, 0x1F105 },
  { 0x1F106, 0x1F106 },
  { 0x1F107, 0x1F107 },
  { 0x1F108, 0x1F108 },
  { 0x1F109, 0x1F109 },
  { 0x1F10A, 0x1F10A },
  { 0x1F110, 0x1F110 },
  { 0x1F111, 0x1F111 },
  { 0x1F112, 0x1F112 },
  { 0x1F113, 0x1F113 },
  { 0x1F114, 0x1F114 },
  { 0x1F115, 0x1F115 },
  { 0x1F116, 0x1F116 },
  { 0x1F117, 0x1F117 },
  { 0x1F118, 0x1F118 },
  { 0x1F119, 0x1F119 },
  { 0x1F11A, 0x1F11A },
  { 0x1F11B, 0x1F11B },
  { 0x1F11C, 0x1F11C },
  { 0x1F11D, 0x1F11D },
  { 0x1F11E, 0x1F11E },
  { 0x1F11F, 0x1F11F },
  { 0x1F120, 0x1F120 },
  { 0x1F121, 0x1F121 },
  { 0x1F122, 0x1F122 },
  { 0x1F123, 0x1F123 },
  { 0x1F124, 0x1F124 },
  { 0x1F125, 0x1F125 },
  { 0x1F126, 0x1F126 },
  { 0x1F127, 0x1F127 },
  { 0x1F128, 0x1F128 },
  { 0x1F129, 0x1F129 },
  { 0x1F1AE, 0x1F1E5 },
  { 0x1F203, 0x1F20F },
  { 0x1F23C, 0x1F23F },
  { 0x1F249, 0x1F24F },
  { 0x1F252, 0x1F25F },
  { 0x1F266, 0x1F2FF },
  { 0x1F6D8, 0x1F6DC },
  { 0x1F6ED, 0x1F6EF },
  { 0x1F6FD, 0x1F6FF },
  { 0x1F774, 0x1F77F },
  { 0x1F7D9, 0x1F7DF },
  { 0x1F7EC, 0x1F7EF },
  { 0x1F7F1, 0x1F7FF },
  { 0x1F80C, 0x1F80F },
  { 0x1F848, 0x1F84F },
  { 0x1F85A, 0x1F85F },
  { 0x1F888, 0x1F88F },
  { 0x1F8AE, 0x1F8AF },
  { 0x1F8B2, 0x1F8FF },
  { 0x1FA54, 0x1FA5F },
  { 0x1FA6E, 0x1FA6F },
  { 0x1FA75, 0x1FA77 },
  { 0x1FA7D, 0x1FA7F },
  { 0x1FA87, 0x1FA8F },
  { 0x1FAAD, 0x1FAAF },
  { 0x1FABB, 0x1FABF },
  { 0x1FAC6, 0x1FACF },
  { 0x1FADA, 0x1FADF },
  { 0x1FAE8, 0x1FAEF },
  { 0x1FAF7, 0x1FAFF },
  { 0x1FB93, 0x1FB93 },
  { 0x1FBCB, 0x1FBEF },
  { 0x1FBFA, 0x1FFFD },
  { 0x1FFFE, 0x1FFFF },
  { 0x2A6E0, 0x2A6FF },
  { 0x2B739, 0x2B73F },
  { 0x2B81E, 0x2B81F },
  { 0x2CEA2, 0x2CEAF },
  { 0x2EBE1, 0x2F7FF },
  { 0x2F868, 0x2F868 },
  { 0x2F874, 0x2F874 },
  { 0x2F91F, 0x2F91F },
  { 0x2F95F, 0x2F95F },
  { 0x2F9BF, 0x2F9BF },
  { 0x2FA1E, 0x2FFFD },
  { 0x2FFFE, 0x2FFFF },
  { 0x3134B, 0x3FFFD },
  { 0x3FFFE, 0x3FFFF },
  { 0x40000, 0x4FFFD },
  { 0x4FFFE, 0x4FFFF },
  { 0x50000, 0x5FFFD },
  { 0x5FFFE, 0x5FFFF },
  { 0x60000, 0x6FFFD },
  { 0x6FFFE, 0x6FFFF },
  { 0x70000, 0x7FFFD },
  { 0x7FFFE, 0x7FFFF },
  { 0x80000, 0x8FFFD },
  { 0x8FFFE, 0x8FFFF },
  { 0x90000, 0x9FFFD },
  { 0x9FFFE, 0x9FFFF },
  { 0xA0000, 0xAFFFD },
  { 0xAFFFE, 0xAFFFF },
  { 0xB0000, 0xBFFFD },
  { 0xBFFFE, 0xBFFFF },
  { 0xC0000, 0xCFFFD },
  { 0xCFFFE, 0xCFFFF },
  { 0xD0000, 0xDFFFD },
  { 0xDFFFE, 0xDFFFF },
  { 0xE0000, 0xE0000 },
  { 0xE0001, 0xE0001 },
  { 0xE0002, 0xE001F },
  { 0xE0020, 0xE007F },
  { 0xE0080, 0xE00FF },
  { 0xE01F0, 0xEFFFD },
  { 0xEFFFE, 0xEFFFF },
  { 0xF0000, 0xFFFFD },
  { 0xFFFFE, 0xFFFFF },
  { 0x100000, 0x10FFFD },
  { 0x10FFFE, 0x10FFFF }
};

// https://unicode.org/Public/14.0.0/ucd/UnicodeData-14.0.0d13.txt
// cut -d';' -f1,3 | grep -E 'M[nec]' | cut -d';' -f1
static uint32_t marks[][2] = {
  { 0x0300, 0x036F },
  { 0x0483, 0x0489 },
  { 0x0591, 0x05BD },
  { 0x05BF, 0x05BF },
  { 0x05C1, 0x05C2 },
  { 0x05C4, 0x05C5 },
  { 0x05C7, 0x05C7 },
  { 0x0610, 0x061A },
  { 0x064B, 0x065F },
  { 0x0670, 0x0670 },
  { 0x06D6, 0x06DC },
  { 0x06DF, 0x06E4 },
  { 0x06E7, 0x06E8 },
  { 0x06EA, 0x06ED },
  { 0x0711, 0x0711 },
  { 0x0730, 0x074A },
  { 0x07A6, 0x07B0 },
  { 0x07EB, 0x07F3 },
  { 0x07FD, 0x07FD },
  { 0x0816, 0x0819 },
  { 0x081B, 0x0823 },
  { 0x0825, 0x0827 },
  { 0x0829, 0x082D },
  { 0x0859, 0x085B },
  { 0x0898, 0x089F },
  { 0x08CA, 0x08E1 },
  { 0x08E3, 0x0903 },
  { 0x093A, 0x093C },
  { 0x093E, 0x094F },
  { 0x0951, 0x0957 },
  { 0x0962, 0x0963 },
  { 0x0981, 0x0983 },
  { 0x09BC, 0x09BC },
  { 0x09BE, 0x09C4 },
  { 0x09C7, 0x09C8 },
  { 0x09CB, 0x09CD },
  { 0x09D7, 0x09D7 },
  { 0x09E2, 0x09E3 },
  { 0x09FE, 0x09FE },
  { 0x0A01, 0x0A03 },
  { 0x0A3C, 0x0A3C },
  { 0x0A3E, 0x0A42 },
  { 0x0A47, 0x0A48 },
  { 0x0A4B, 0x0A4D },
  { 0x0A51, 0x0A51 },
  { 0x0A70, 0x0A71 },
  { 0x0A75, 0x0A75 },
  { 0x0A81, 0x0A83 },
  { 0x0ABC, 0x0ABC },
  { 0x0ABE, 0x0AC5 },
  { 0x0AC7, 0x0AC9 },
  { 0x0ACB, 0x0ACD },
  { 0x0AE2, 0x0AE3 },
  { 0x0AFA, 0x0AFF },
  { 0x0B01, 0x0B03 },
  { 0x0B3C, 0x0B3C },
  { 0x0B3E, 0x0B44 },
  { 0x0B47, 0x0B48 },
  { 0x0B4B, 0x0B4D },
  { 0x0B55, 0x0B57 },
  { 0x0B62, 0x0B63 },
  { 0x0B82, 0x0B82 },
  { 0x0BBE, 0x0BC2 },
  { 0x0BC6, 0x0BC8 },
  { 0x0BCA, 0x0BCD },
  { 0x0BD7, 0x0BD7 },
  { 0x0C00, 0x0C04 },
  { 0x0C3C, 0x0C3C },
  { 0x0C3E, 0x0C44 },
  { 0x0C46, 0x0C48 },
  { 0x0C4A, 0x0C4D },
  { 0x0C55, 0x0C56 },
  { 0x0C62, 0x0C63 },
  { 0x0C81, 0x0C83 },
  { 0x0CBC, 0x0CBC },
  { 0x0CBE, 0x0CC4 },
  { 0x0CC6, 0x0CC8 },
  { 0x0CCA, 0x0CCD },
  { 0x0CD5, 0x0CD6 },
  { 0x0CE2, 0x0CE3 },
  { 0x0D00, 0x0D03 },
  { 0x0D3B, 0x0D3C },
  { 0x0D3E, 0x0D44 },
  { 0x0D46, 0x0D48 },
  { 0x0D4A, 0x0D4D },
  { 0x0D57, 0x0D57 },
  { 0x0D62, 0x0D63 },
  { 0x0D81, 0x0D83 },
  { 0x0DCA, 0x0DCA },
  { 0x0DCF, 0x0DD4 },
  { 0x0DD6, 0x0DD6 },
  { 0x0DD8, 0x0DDF },
  { 0x0DF2, 0x0DF3 },
  { 0x0E31, 0x0E31 },
  { 0x0E34, 0x0E3A },
  { 0x0E47, 0x0E4E },
  { 0x0EB1, 0x0EB1 },
  { 0x0EB4, 0x0EBC },
  { 0x0EC8, 0x0ECD },
  { 0x0F18, 0x0F19 },
  { 0x0F35, 0x0F35 },
  { 0x0F37, 0x0F37 },
  { 0x0F39, 0x0F39 },
  { 0x0F3E, 0x0F3F },
  { 0x0F71, 0x0F84 },
  { 0x0F86, 0x0F87 },
  { 0x0F8D, 0x0F97 },
  { 0x0F99, 0x0FBC },
  { 0x0FC6, 0x0FC6 },
  { 0x102B, 0x103E },
  { 0x1056, 0x1059 },
  { 0x105E, 0x1060 },
  { 0x1062, 0x1064 },
  { 0x1067, 0x106D },
  { 0x1071, 0x1074 },
  { 0x1082, 0x108D },
  { 0x108F, 0x108F },
  { 0x109A, 0x109D },
  { 0x135D, 0x135F },
  { 0x1712, 0x1715 },
  { 0x1732, 0x1734 },
  { 0x1752, 0x1753 },
  { 0x1772, 0x1773 },
  { 0x17B4, 0x17D3 },
  { 0x17DD, 0x17DD },
  { 0x180B, 0x180D },
  { 0x180F, 0x180F },
  { 0x1885, 0x1886 },
  { 0x18A9, 0x18A9 },
  { 0x1920, 0x192B },
  { 0x1930, 0x193B },
  { 0x1A17, 0x1A1B },
  { 0x1A55, 0x1A5E },
  { 0x1A60, 0x1A7C },
  { 0x1A7F, 0x1A7F },
  { 0x1AB0, 0x1ACE },
  { 0x1B00, 0x1B04 },
  { 0x1B34, 0x1B44 },
  { 0x1B6B, 0x1B73 },
  { 0x1B80, 0x1B82 },
  { 0x1BA1, 0x1BAD },
  { 0x1BE6, 0x1BF3 },
  { 0x1C24, 0x1C37 },
  { 0x1CD0, 0x1CD2 },
  { 0x1CD4, 0x1CE8 },
  { 0x1CED, 0x1CED },
  { 0x1CF4, 0x1CF4 },
  { 0x1CF7, 0x1CF9 },
  { 0x1DC0, 0x1DFF },
  { 0x20D0, 0x20F0 },
  { 0x2CEF, 0x2CF1 },
  { 0x2D7F, 0x2D7F },
  { 0x2DE0, 0x2DFF },
  { 0x302A, 0x302F },
  { 0x3099, 0x309A },
  { 0xA66F, 0xA672 },
  { 0xA674, 0xA67D },
  { 0xA69E, 0xA69F },
  { 0xA6F0, 0xA6F1 },
  { 0xA802, 0xA802 },
  { 0xA806, 0xA806 },
  { 0xA80B, 0xA80B },
  { 0xA823, 0xA827 },
  { 0xA82C, 0xA82C },
  { 0xA880, 0xA881 },
  { 0xA8B4, 0xA8C5 },
  { 0xA8E0, 0xA8F1 },
  { 0xA8FF, 0xA8FF },
  { 0xA926, 0xA92D },
  { 0xA947, 0xA953 },
  { 0xA980, 0xA983 },
  { 0xA9B3, 0xA9C0 },
  { 0xA9E5, 0xA9E5 },
  { 0xAA29, 0xAA36 },
  { 0xAA43, 0xAA43 },
  { 0xAA4C, 0xAA4D },
  { 0xAA7B, 0xAA7D },
  { 0xAAB0, 0xAAB0 },
  { 0xAAB2, 0xAAB4 },
  { 0xAAB7, 0xAAB8 },
  { 0xAABE, 0xAABF },
  { 0xAAC1, 0xAAC1 },
  { 0xAAEB, 0xAAEF },
  { 0xAAF5, 0xAAF6 },
  { 0xABE3, 0xABEA },
  { 0xABEC, 0xABED },
  { 0xFB1E, 0xFB1E },
  { 0xFE00, 0xFE0F },
  { 0xFE20, 0xFE2F },
  { 0x101FD, 0x101FD },
  { 0x102E0, 0x102E0 },
  { 0x10376, 0x1037A },
  { 0x10A01, 0x10A03 },
  { 0x10A05, 0x10A06 },
  { 0x10A0C, 0x10A0F },
  { 0x10A38, 0x10A3A },
  { 0x10A3F, 0x10A3F },
  { 0x10AE5, 0x10AE6 },
  { 0x10D24, 0x10D27 },
  { 0x10EAB, 0x10EAC },
  { 0x10F46, 0x10F50 },
  { 0x10F82, 0x10F85 },
  { 0x11000, 0x11002 },
  { 0x11038, 0x11046 },
  { 0x11070, 0x11070 },
  { 0x11073, 0x11074 },
  { 0x1107F, 0x11082 },
  { 0x110B0, 0x110BA },
  { 0x110C2, 0x110C2 },
  { 0x11100, 0x11102 },
  { 0x11127, 0x11134 },
  { 0x11145, 0x11146 },
  { 0x11173, 0x11173 },
  { 0x11180, 0x11182 },
  { 0x111B3, 0x111C0 },
  { 0x111C9, 0x111CC },
  { 0x111CE, 0x111CF },
  { 0x1122C, 0x11237 },
  { 0x1123E, 0x1123E },
  { 0x112DF, 0x112EA },
  { 0x11300, 0x11303 },
  { 0x1133B, 0x1133C },
  { 0x1133E, 0x11344 },
  { 0x11347, 0x11348 },
  { 0x1134B, 0x1134D },
  { 0x11357, 0x11357 },
  { 0x11362, 0x11363 },
  { 0x11366, 0x1136C },
  { 0x11370, 0x11374 },
  { 0x11435, 0x11446 },
  { 0x1145E, 0x1145E },
  { 0x114B0, 0x114C3 },
  { 0x115AF, 0x115B5 },
  { 0x115B8, 0x115C0 },
  { 0x115DC, 0x115DD },
  { 0x11630, 0x11640 },
  { 0x116AB, 0x116B7 },
  { 0x1171D, 0x1172B },
  { 0x1182C, 0x1183A },
  { 0x11930, 0x11935 },
  { 0x11937, 0x11938 },
  { 0x1193B, 0x1193E },
  { 0x11940, 0x11940 },
  { 0x11942, 0x11943 },
  { 0x119D1, 0x119D7 },
  { 0x119DA, 0x119E0 },
  { 0x119E4, 0x119E4 },
  { 0x11A01, 0x11A0A },
  { 0x11A33, 0x11A39 },
  { 0x11A3B, 0x11A3E },
  { 0x11A47, 0x11A47 },
  { 0x11A51, 0x11A5B },
  { 0x11A8A, 0x11A99 },
  { 0x11C2F, 0x11C36 },
  { 0x11C38, 0x11C3F },
  { 0x11C92, 0x11CA7 },
  { 0x11CA9, 0x11CB6 },
  { 0x11D31, 0x11D36 },
  { 0x11D3A, 0x11D3A },
  { 0x11D3C, 0x11D3D },
  { 0x11D3F, 0x11D45 },
  { 0x11D47, 0x11D47 },
  { 0x11D8A, 0x11D8E },
  { 0x11D90, 0x11D91 },
  { 0x11D93, 0x11D97 },
  { 0x11EF3, 0x11EF6 },
  { 0x16AF0, 0x16AF4 },
  { 0x16B30, 0x16B36 },
  { 0x16F4F, 0x16F4F },
  { 0x16F51, 0x16F87 },
  { 0x16F8F, 0x16F92 },
  { 0x16FE4, 0x16FE4 },
  { 0x16FF0, 0x16FF1 },
  { 0x1BC9D, 0x1BC9E },
  { 0x1CF00, 0x1CF2D },
  { 0x1CF30, 0x1CF46 },
  { 0x1D165, 0x1D169 },
  { 0x1D16D, 0x1D172 },
  { 0x1D17B, 0x1D182 },
  { 0x1D185, 0x1D18B },
  { 0x1D1AA, 0x1D1AD },
  { 0x1D242, 0x1D244 },
  { 0x1DA00, 0x1DA36 },
  { 0x1DA3B, 0x1DA6C },
  { 0x1DA75, 0x1DA75 },
  { 0x1DA84, 0x1DA84 },
  { 0x1DA9B, 0x1DA9F },
  { 0x1DAA1, 0x1DAAF },
  { 0x1E000, 0x1E006 },
  { 0x1E008, 0x1E018 },
  { 0x1E01B, 0x1E021 },
  { 0x1E023, 0x1E024 },
  { 0x1E026, 0x1E02A },
  { 0x1E130, 0x1E136 },
  { 0x1E2AE, 0x1E2AE },
  { 0x1E2EC, 0x1E2EF },
  { 0x1E8D0, 0x1E8D6 },
  { 0x1E944, 0x1E94A },
  { 0xE0100, 0xE01EF }
};

int idna_disallow(uint32_t cp) {
  size_t i, l, h;

  l = 0;
  h = sizeof disallowed / sizeof disallowed[0] - 1;

  do {
    i = (l + h) >> 1;

    if (cp < disallowed[i][0])
      h = i - 1;
    else if (cp > disallowed[i][1])
      l = i + 1;
    else
      return 1;
  } while (l <= h);

  return 0;
}

int idna_mark(uint32_t cp) {
  size_t i, l, h;

  l = 0;
  h = sizeof marks / sizeof marks[0] - 1;

  do {
    i = (l + h) >> 1;

    if (cp < marks[i][0]) {
      if (h == 0)
        break;

      h = i - 1;
    } else if (cp > marks[i][1])
      l = i + 1;
    else
      return 1;
  } while (l <= h);

  return 0;
}
