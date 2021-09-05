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
