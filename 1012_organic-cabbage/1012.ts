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

  const [[testCount], ...lines] = input.split('\n').map((line) => {
    return line.split(' ').map((n) => {
      return parseInt(n);
    });
  });

  const dfs = ({
    matrix,
    visited,
    x,
    y,
  }: {
    matrix: Array<Array<boolean>>;
    visited: Array<Array<boolean>>;
    x: number;
    y: number;
  }): void => {
    visited[x][y] = true;
    const hasCabbage = matrix[x][y];

    if (!hasCabbage) {
      return;
    }

    const around = [
      [x, Math.max(y - 1, 0)],
      [x, Math.min(y + 1, matrix[x].length - 1)],
      [Math.max(x - 1, 0), y],
      [Math.min(x + 1, matrix.length - 1), y],
    ];

    // console.log(x, y, around);

    // 상하좌우
    around.forEach(([x, y]) => {
      if (visited[x][y]) {
        return;
      }

      dfs({ matrix, visited, x, y });
    });
  };

  for (let i = 1; i <= testCount; ++i) {
    const data = lines.shift();

    if (!data) {
      continue;
    }

    const [rowCount, colCount, _posCount] = data;
    const matrix: Array<Array<boolean>> = new Array(rowCount)
      .fill(null)
      .map(() => new Array(colCount).fill(false));
    let posCount = _posCount;

    while (posCount--) {
      const position = lines.shift();

      if (!position) {
        continue;
      }

      const [x, y] = position;
      matrix[x][y] = true;
    }

    // console.log('matrix', matrix);
    const visited: Array<Array<boolean>> = new Array(rowCount)
      .fill(null)
      .map(() => new Array(colCount).fill(false));
    let count = 0;
    matrix.forEach((rows, x) => {
      rows.forEach((_, y) => {
        if (visited[x][y]) {
          return;
        }

        if (!matrix[x][y]) {
          visited[x][y] = true;

          return;
        }

        ++count;
        dfs({ matrix, visited, x, y });
      });
    });
    console.log(count);
  }
})();
