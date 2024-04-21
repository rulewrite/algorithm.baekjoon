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

  const lcs: Array<string> = [];
  let i = aText.length;
  let j = bText.length;
  while (i > 0 && j > 0) {
    if (aText[i - 1] === bText[j - 1]) {
      lcs.unshift(aText[i - 1]);
      // 좌상단(대각선)으로 이동
      --i;
      --j;
      continue;
    }

    if (dp[i - 1][j] > dp[i][j - 1]) {
      // 상단으로 이동
      --i;
      continue;
    }

    // 좌로 이동
    --j;
  }

  console.log(`${dp[aText.length][bText.length]}\n${lcs.join('')}`);
})();
