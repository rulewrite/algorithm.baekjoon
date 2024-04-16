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
    Wall = 1,
    Road = 0,
  }

  const [[rowCount, colCount], ...matrix] = input
    .split('\n')
    .map((line, index) => {
      return line.split(index === 0 ? ' ' : '').map((n) => parseInt(n));
    });

  interface Node {
    rowIndex: number;
    colIndex: number;
  }

  const getId = (node: Node): string => {
    return `${node.rowIndex},${node.colIndex}`;
  };

  const getNeighbors = (() => {
    const directions = [
      [-1, 0],
      [1, 0],
      [0, -1],
      [0, 1],
    ];
    const rowLastIndex = rowCount - 1;
    const colLastIndex = colCount - 1;

    return ({ rowIndex, colIndex }: Node): Array<Node> => {
      // 상하좌우
      return directions
        .map(([_row, _col]) => {
          return {
            rowIndex: rowIndex + _row,
            colIndex: colIndex + _col,
          };
        })
        .filter((neighbor) => {
          return (
            neighbor.rowIndex >= 0 &&
            neighbor.colIndex >= 0 &&
            neighbor.rowIndex <= rowLastIndex &&
            neighbor.colIndex <= colLastIndex
          );
        });
    };
  })();

  const goal: Node = {
    rowIndex: rowCount - 1,
    colIndex: colCount - 1,
  };

  const bfs = ({ startNode }: { startNode: Node }): number => {
    const queue: Array<{
      node: Node;
      distance: number;
      breakId: null | string;
      visiteds: Array<string>;
    }> = [
      {
        node: startNode,
        distance: 0,
        breakId: null,
        visiteds: [getId(startNode)],
      },
    ];

    while (queue.length) {
      const { node, distance, breakId, visiteds } = queue.shift()!;

      if (node.colIndex === goal.colIndex && node.rowIndex === goal.rowIndex) {
        return distance + 1;
      }

      getNeighbors(node).forEach((neighbor) => {
        const id = getId(neighbor);
        if (visiteds.includes(id)) {
          return;
        }

        const status = matrix[neighbor.rowIndex][neighbor.colIndex];
        if (status === Status.Road) {
          queue.push({
            node: neighbor,
            distance: distance + 1,
            breakId,
            visiteds: [...visiteds, id],
          });
          return;
        }

        if (breakId !== null) {
          return;
        }

        queue.push({
          node: neighbor,
          distance: distance + 1,
          breakId: id,
          visiteds: [...visiteds, id],
        });
      });
    }

    return -1;
  };

  console.log(
    bfs({
      startNode: {
        rowIndex: 0,
        colIndex: 0,
      },
    })
  );
})();
