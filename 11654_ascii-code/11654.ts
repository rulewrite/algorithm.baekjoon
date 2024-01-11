const inputString: string = require('fs')
  .readFileSync('/dev/stdin')
  .toString()
  .trim();

console.log(inputString.charCodeAt(0));
