```
npm i mjethani/domaintoascii
```

```html
<script type="module">
  import { domainToASCII } from 'https://mjethani.github.io/domaintoascii/index.js';

  let ascii = domainToASCII('i❤️.ws');
  console.log(ascii); // xn--i-7iq.ws
</script>
```

---

This is an implementation of Node.js's [`url.domainToASCII()`](https://nodejs.org/api/url.html#url_url_domaintoascii_domain) in WebAssembly.

The current version is based on [Unicode 14.0.0](https://unicode.org/versions/Unicode14.0.0/).

It implements the algorithm described in [UTS #46](https://unicode.org/reports/tr46/), with __non-transitional processing__ and __UseSTD3ASCIIRules=false__.

## Demo

See [demo.html](https://mjethani.github.io/domaintoascii/demo.html)

## API

### `domainToASCII(domain, { skipIDNA = false } = {})`

Same as [`url.domainToASCII()`](https://nodejs.org/api/url.html#url_url_domaintoascii_domain) except as noted below.

* `skipIDNA`: If `true`, skips [IDNA mapping and validation](https://www.unicode.org/reports/tr46/#ToASCII) and jumps straight to Punycode encoding. __Default__: `false`.

## Performance

```console
$ npm run benchmark

> domaintoascii@0.1.0 benchmark
> node scripts/benchmark.js

native: 87.021ms
Generated 1,024,580 characters

domaintoascii: 64.457ms
Generated 1,024,580 characters

punycode.js: 145.172ms
Generated 1,024,580 characters

domaintoascii { skipIDNA=true }: 33.507ms
Generated 1,024,580 characters

$ 
```

## Development

Run `npm run build-idna-tables` to regenerate the IDNA tables in `idna_tables-generated.h`.

Make sure [Emscripten](https://emscripten.org/) is installed and set up and then run `make clean all` to rebuild `encoder.wasm`.

Ideas are [welcome](https://github.com/mjethani/domaintoascii/issues).

---

[![Tests](https://github.com/mjethani/domaintoascii/actions/workflows/tests.yml/badge.svg)](https://github.com/mjethani/domaintoascii/actions/workflows/tests.yml)
