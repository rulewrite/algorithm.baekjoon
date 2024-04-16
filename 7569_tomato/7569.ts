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

  const getId = (node: Node): string => {
    return `${node.rowIndex},${node.colIndex},${node.floorIndex}`;
  };

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

  const hasIsolated = matrix.some((rows, floorIndex) => {
    return rows.some((cols, rowIndex) => {
      return cols.some((status, colIndex) => {
        const node = { floorIndex, rowIndex, colIndex };

        if (status !== Status.Unripe) {
          return false;
        }

        const hasRoute = getNeighbors(node).some((neighbor) => {
          const status =
            matrix[neighbor.floorIndex][neighbor.rowIndex][neighbor.colIndex];

          return status !== Status.Empty;
        });

        return !hasRoute;
      });
    });
  });

  if (hasIsolated) {
    console.log(-1);
    return;
  }

  let time = 0;
  while (true) {
    const hasUnripen = matrix.some((rows) => {
      return rows.some((cols) => {
        return cols.includes(Status.Unripe);
      });
    });

    if (!hasUnripen) {
      console.log(time);

      break;
    }

    ++time;
    const visiteds = new Set<string>();
    matrix.forEach((rows, floorIndex) => {
      rows.forEach((cols, rowIndex) => {
        cols.forEach((status, colIndex) => {
          const node = { floorIndex, rowIndex, colIndex };

          if (status !== Status.Ripe) {
            return;
          }

          const id = getId(node);
          if (visiteds.has(id)) {
            return;
          }
          visiteds.add(id);

          getNeighbors(node).forEach((neighbor) => {
            const id = getId(neighbor);
            if (visiteds.has(id)) {
              return;
            }
            visiteds.add(id);

            const status =
              matrix[neighbor.floorIndex][neighbor.rowIndex][neighbor.colIndex];

            if (status !== Status.Unripe) {
              return;
            }

            matrix[neighbor.floorIndex][neighbor.rowIndex][neighbor.colIndex] =
              Status.Ripe;
          });
        });
      });
    });
  }
})();
