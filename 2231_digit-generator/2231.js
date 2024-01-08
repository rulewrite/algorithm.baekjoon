const input = require('fs')
  .readFileSync(
    process.platform === 'linux'
      ? '/dev/stdin'
      : require('path').resolve(__dirname, 'example.txt')
  )
  .toString()
  .trim();

const N = parseInt(input);

let M = 0;
for (let i = 0; i < N; i++) {
  let sum = i;

  const stringValue = i.toString();
  for (let j = 0; j < stringValue.length; j++) {
    sum += parseInt(stringValue[j]);
  }

  if (sum === N) {
    M = i;
    break;
  }
}

console.log(M);
