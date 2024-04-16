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

  enum Status {
    Empty = -1,
    Unripe = 0,
    Ripe = 1,
  }

  const [[colCount, rowCount, floorCount], ...input2] = input
    .split('\n')
    .map((line) => {
      return line.split(' ').map((n) => parseInt(n));
    });

  const matrix = input2.reduce((arr, item, idx) => {
    if (idx % rowCount === 0) {
      return [...arr, [item]];
    }

    return [...arr.slice(0, -1), [...arr.slice(-1)[0], item]];
  }, [] as Array<Array<Array<Status>>>);

  interface Node {
    rowIndex: number;
    colIndex: number;
    floorIndex: number;
  }

  // 위아래-상하좌우
  const getNeighbors = (() => {
    const rowLastIndex = rowCount - 1;
    const colLastIndex = colCount - 1;
    const floorLastIndex = floorCount - 1;

    const positions = [
      [-1, 0, 0],
      [1, 0, 0],
      [0, -1, 0],
      [0, 1, 0],
      [0, 0, -1],
      [0, 0, 1],
    ];

    return (node: Node): Array<Node> => {
      return positions
        .map(([floorIndex, rowIndex, colIndex]) => {
          return {
            floorIndex: node.floorIndex + floorIndex,
            rowIndex: node.rowIndex + rowIndex,
            colIndex: node.colIndex + colIndex,
          };
        })
        .filter((neighbor) => {
          return (
            neighbor.floorIndex >= 0 &&
            neighbor.rowIndex >= 0 &&
            neighbor.colIndex >= 0 &&
            neighbor.floorIndex <= floorLastIndex &&
            neighbor.rowIndex <= rowLastIndex &&
            neighbor.colIndex <= colLastIndex
          );
        });
    };
  })();

  let ripeTomatoes: Node[] = [];
  matrix.forEach((rows, floorIndex) => {
    rows.forEach((cols, rowIndex) => {
      cols.forEach((status, colIndex) => {
        if (status !== Status.Ripe) {
          return;
        }

        ripeTomatoes.push({ floorIndex, rowIndex, colIndex });
      });
    });
  });

  let time = 0;
  while (ripeTomatoes.length > 0) {
    ++time;
    const nextRipeTomatoes: Node[] = [];

    ripeTomatoes.forEach((node) => {
      getNeighbors(node).forEach((neighbor) => {
        const status =
          matrix[neighbor.floorIndex][neighbor.rowIndex][neighbor.colIndex];

        if (status !== Status.Unripe) {
          return;
        }

        matrix[neighbor.floorIndex][neighbor.rowIndex][neighbor.colIndex] =
          Status.Ripe;

        nextRipeTomatoes.push(neighbor);
      });
    });

    ripeTomatoes = nextRipeTomatoes;
  }

  const hasUnripe = matrix.some((rows) => {
    return rows.some((cols) => {
      return cols.includes(Status.Unripe);
    });
  });

  console.log(hasUnripe ? -1 : time - 1);
})();
