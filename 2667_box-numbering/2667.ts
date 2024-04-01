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

  const [_, ...matrix] = input.split('\n').map((line) => {
    return line.split('').map((n) => n === '1');
  });

  const width = matrix[0].length - 1;
  const height = matrix.length - 1;
  const getNeighbors = ({
    x,
    y,
  }: {
    x: number;
    y: number;
  }): Array<{ x: number; y: number }> => {
    // 상하좌우
    return [
      { x, y: Math.max(y - 1, 0) },
      { x, y: Math.min(y + 1, height) },
      { x: Math.max(x - 1, 0), y },
      { x: Math.min(x + 1, width), y },
    ];
  };

  const boxes: Array<number> = [];
  const dfs = ({
    x,
    y,
    boxIndex,
  }: {
    x: number;
    y: number;
    boxIndex: number;
  }) => {
    getNeighbors({ x, y }).forEach((neighbor) => {
      if (!matrix[neighbor.x][neighbor.y]) {
        return;
      }

      ++boxes[boxIndex];
      matrix[neighbor.x][neighbor.y] = false;
      dfs({ x: neighbor.x, y: neighbor.y, boxIndex });
    });
  };

  matrix.forEach((rows, x) => {
    rows.forEach((hasHome, y) => {
      if (!hasHome) {
        return;
      }

      matrix[x][y] = false;
      boxes.push(1);
      dfs({ x, y, boxIndex: boxes.length - 1 });
    });
  });

  boxes.sort((a, b) => a - b);
  console.log(`${boxes.length}\n${boxes.join('\n')}`);
})();
