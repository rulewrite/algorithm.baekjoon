const input = require('fs')
  .readFileSync(
    process.platform === 'linux'
      ? '/dev/stdin'
      : require('path').resolve(__dirname, 'example.txt')
  )
  .toString()
  .trim();

const lines = input.split('\n');

const lineToNums = lines.map((line) => {
  return line.split(' ').map((n) => {
    return parseInt(n);
  });
});

const [rowLength] = lineToNums.shift();

const [aMatrix, bMatrix] = [
  lineToNums.slice(0, rowLength),
  lineToNums.slice(rowLength, lineToNums.length),
];

const result = aMatrix
  .map((row, rowIndex) => {
    return row
      .map((col, colIndex) => {
        return col + bMatrix[rowIndex][colIndex];
      })
      .join(' ');
  })
  .join('\n');

console.log(result);
