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

  const lines = input.split('\n').map((line) => {
    return line.split(' ').map((n) => parseInt(n));
  });
  // console.log(lines);

  const getNeighbors = ({
    matrix,
    x,
    y,
  }: {
    matrix: Array<Array<number>>;
    x: number;
    y: number;
  }) => {
    const width = matrix.length - 1;
    const height = matrix[0].length - 1;

    const top = Math.max(y - 1, 0);
    const bottom = Math.min(y + 1, height);
    const right = Math.min(x + 1, width);
    const left = Math.max(x - 1, 0);

    // 12시부터 시계방향
    return [
      { x, y: top },
      { x: right, y: top },
      { x: right, y },
      { x: right, y: bottom },
      { x, y: bottom },
      { x: left, y: bottom },
      { x: left, y },
      { x: left, y: top },
    ];
  };

  const dfs = ({
    matrix,
    x,
    y,
  }: {
    matrix: Array<Array<number>>;
    x: number;
    y: number;
  }) => {
    getNeighbors({ matrix, x, y }).forEach((neighbor) => {
      if (!matrix[neighbor.x][neighbor.y]) {
        return;
      }

      matrix[neighbor.x][neighbor.y] = 0;
      dfs({
        matrix,
        x: neighbor.x,
        y: neighbor.y,
      });
    });
  };

  const result: Array<number> = [];
  let i = 0;
  while (true) {
    const [width, height] = lines[i];

    if (!width && !height) {
      break;
    }

    ++i;

    let count = 0;
    const matrix = lines.slice(i, i + height);
    matrix.forEach((rows, x) => {
      rows.forEach((isLand, y) => {
        if (!isLand) {
          return;
        }

        matrix[x][y] = 0;
        ++count;
        dfs({ matrix, x, y });
      });
    });
    result.push(count);

    i += height;
  }

  console.log(result.join('\n'));
})();
