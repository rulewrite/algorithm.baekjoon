(() => {
  const isBaekjoon = process.platform === 'linux';
  const input: string = require('fs')
    .readFileSync(
      isBaekjoon
        ? '/dev/stdin'
        : require('path').resolve(__dirname, 'example.txt')
    )
    .toString()
    .trim();

  const [[numbersLength], numbers] = input.split('\n').map((line) => {
    return line.split(' ').map((n) => {
      return parseInt(n);
    });
  });
  const lastIndex = numbersLength - 1;

  const sum = (indicies: Array<number>): number => {
    const sortedNumbers = indicies.map((index) => {
      return numbers[index];
    });

    const result = sortedNumbers.reduce((acc, num, i) => {
      if (i === lastIndex) {
        return acc;
      }

      return acc + Math.abs(num - sortedNumbers[i + 1]);
    }, 0);

    // console.log(sortedNumbers, result);
    return result;
  };

  let maximum = 0;

  const dfs = (indicies: Array<number>) => {
    if (numbersLength === indicies.length) {
      maximum = Math.max(maximum, sum(indicies));
      return;
    }

    for (let i = 0; i < numbersLength; ++i) {
      if (indicies.includes(i)) {
        continue;
      }

      indicies.push(i);
      dfs(indicies);
      indicies.pop();
    }
  };
  dfs([]);

  console.log(maximum);
})();
