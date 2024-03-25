const isBaekjoon = process.platform === 'linux';
const input: string = require('fs')
  .readFileSync(
    isBaekjoon
      ? '/dev/stdin'
      : require('path').resolve(__dirname, 'example.txt')
  )
  .toString()
  .trim();

const [a, b] = input.split(' ').map((n) => parseInt(n));

console.log(a + b);
