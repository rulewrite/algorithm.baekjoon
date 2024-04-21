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

  const [aText, bText, cText] = input.split('\n');

  const buffer = 1;
  const dp = Array.from({ length: aText.length + buffer }, () => {
    return Array.from({ length: bText.length + buffer }, () => {
      return new Array(cText.length + buffer).fill(0);
    });
  });

  for (let i = 0; i < aText.length; ++i) {
    for (let j = 0; j < bText.length; ++j) {
      for (let k = 0; k < cText.length; ++k) {
        const dpAIndex = i + buffer;
        const dpBIndex = j + buffer;
        const dpCIndex = k + buffer;

        if (aText[i] === bText[j] && bText[j] === cText[k]) {
          dp[dpAIndex][dpBIndex][dpCIndex] =
            dp[dpAIndex - 1][dpBIndex - 1][dpCIndex - 1] + 1;
          continue;
        }

        dp[dpAIndex][dpBIndex][dpCIndex] = Math.max(
          dp[dpAIndex - 1][dpBIndex][dpCIndex],
          dp[dpAIndex][dpBIndex - 1][dpCIndex],
          dp[dpAIndex][dpBIndex][dpCIndex - 1]
        );
      }
    }
  }

  console.log(dp[aText.length][bText.length][cText.length]);
})();
