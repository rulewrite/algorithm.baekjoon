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

  const [aText, bText] = input.split('\n');

  const buffer = 1;
  const dp = Array.from({ length: aText.length + buffer }, () => {
    return new Array(bText.length + buffer).fill(0);
  });

  for (let i = 0; i < aText.length; ++i) {
    for (let j = 0; j < bText.length; ++j) {
      const dpAIndex = i + buffer;
      const dpBIndex = j + buffer;

      if (aText[i] === bText[j]) {
        dp[dpAIndex][dpBIndex] = dp[dpAIndex - 1][dpBIndex - 1] + 1;
        continue;
      }

      dp[dpAIndex][dpBIndex] = Math.max(
        dp[dpAIndex][dpBIndex - 1],
        dp[dpAIndex - 1][dpBIndex]
      );
    }
  }

  console.log(dp[aText.length][bText.length]);
})();
