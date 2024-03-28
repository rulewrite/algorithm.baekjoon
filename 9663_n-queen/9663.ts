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

  const N = parseInt(input);

  const columns = new Array(N).fill(false);
  const diagonalLength = 2 * N - 1;
  const topRightToBottomLefts = new Array(diagonalLength).fill(false);
  const topLeftToBottomRights = new Array(diagonalLength).fill(false);

  let count = 0;
  let result = 0;
  const lastIndex = N - 1;

  const backtrack = (x: number) => {
    if (count === N) {
      ++result;
      return;
    }

    for (let y = 0; y < N; ++y) {
      const LBRTIndex = x + y;
      const LTRBIndex = x - y + lastIndex;

      const isSafe =
        !columns[y] &&
        !topRightToBottomLefts[LBRTIndex] &&
        !topLeftToBottomRights[LTRBIndex];

      if (!isSafe) {
        continue;
      }

      columns[y] = true;
      topRightToBottomLefts[LBRTIndex] = true;
      topLeftToBottomRights[LTRBIndex] = true;
      ++count;

      backtrack(x + 1);

      columns[y] = false;
      topRightToBottomLefts[LBRTIndex] = false;
      topLeftToBottomRights[LTRBIndex] = false;
      --count;
    }
  };
  backtrack(0);

  console.log(result);
})();
