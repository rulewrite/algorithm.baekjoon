const input = require('fs')
  .readFileSync(
    process.platform === 'linux'
      ? '/dev/stdin'
      : require('path').resolve(__dirname, 'example.txt')
  )
  .toString()
  .trim()
  .split('\n');

const [, ...aBs] = input;

const result = aBs
  .map((aB) => {
    const [a, b] = aB.split(' ');

    return parseInt(a) + parseInt(b);
  })
  .join('\n');

console.log(result);
