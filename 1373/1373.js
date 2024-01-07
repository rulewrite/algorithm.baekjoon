const input = require('fs')
  .readFileSync(
    process.platform === 'linux'
      ? '/dev/stdin'
      : require('path').resolve(__dirname, 'example.txt')
  )
  .toString()
  .trim();

console.log(parseInt(input, 2).toString(8));
