```
npm i mjethani/domaintoascii
```

```js
import { domainToASCII } from 'domaintoascii';

let ascii = domainToASCII('i❤️.ws');
console.log(ascii); // xn--i-7iq.ws
```

```html
<script type="module">
  import { domainToASCII } from 'https://mjethani.github.io/domaintoascii/index.js';

  let ascii = domainToASCII('i❤️.ws');
  console.log(ascii); // xn--i-7iq.ws
</script>
```

---

[punycode.js](https://github.com/mathiasbynens/punycode.js) has issues.

The input to `punycode.toASCII()` must be [processed](https://github.com/jcranmer/idna-uts46) _before_ it is passed to the function. This makes it difficult to use, especially when the [source of the input](https://publicsuffix.org/list/) is unknown. Node.js has a [native `url.domainToASCII()` API](https://nodejs.org/api/url.html#url_url_domaintoascii_domain) but there is no such thing in the browser.

This implementation uses the [browser's `URL` object](https://developer.mozilla.org/en-US/docs/Web/API/URL) to encode a Unicode domain.

## WebAssembly

Pass `?use-wasm` to the module to use the __experimental__ WebAssembly version.

```js
import { domainToASCII } from 'https://mjethani.github.io/domaintoascii/index.js?use-wasm';
```

## Demo

[URL](https://mjethani.github.io/domaintoascii/demo.html)

[Wasm (experimental)](https://mjethani.github.io/domaintoascii/demo.html?use-wasm)

---

[![Tests](https://github.com/mjethani/domaintoascii/actions/workflows/tests.yml/badge.svg)](https://github.com/mjethani/domaintoascii/actions/workflows/tests.yml)
