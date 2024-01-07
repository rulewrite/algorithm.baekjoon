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

aBs
  .map((aB) => {
    const [a, b] = aB.split(' ');

    return [parseInt(a), parseInt(b)];
  })
  .map(([a, b]) => {
    console.log(a + b);
  });
