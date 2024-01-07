const input = require('fs')
  .readFileSync(
    process.platform === 'linux'
      ? '/dev/stdin'
      : require('path').resolve(__dirname, 'example.txt')
  )
  .toString()
  .trim();

let octal = '';

for (let i = input.length; i >= 0; i -= 3) {
  octal = parseInt(input.slice(Math.max(i - 3, 0), i), 2).toString(8) + octal;
}

console.log(octal);
