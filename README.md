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

It implements the algorithm described in [UTS #46](https://unicode.org/reports/tr46/), with __non-transitional processing__ and __UseSTD3ASCIIRules=true__.

## Demo

See [demo.html](https://mjethani.github.io/domaintoascii/demo.html)

---

[![Tests](https://github.com/mjethani/domaintoascii/actions/workflows/tests.yml/badge.svg)](https://github.com/mjethani/domaintoascii/actions/workflows/tests.yml)
