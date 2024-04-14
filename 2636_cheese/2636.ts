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

  const [[rowCount, colCount], ...grid] = input.split('\n').map((line) => {
    return line.split(' ').map((n) => parseInt(n));
  });
  // console.log(grid);

  interface Node {
    rowIndex: number;
    colIndex: number;
  }

  const getId = (node: Node): string => {
    return `${node.rowIndex},${node.colIndex}`;
  };

  // 상하좌우
  const positions = [
    [-1, 0],
    [1, 0],
    [0, -1],
    [0, 1],
  ];
  const rowLastIndex = rowCount - 1;
  const colLastIndex = colCount - 1;
  const bfs = ({ startNode }: { startNode: Node }): number => {
    let cheeseCount = 0;
    const queue: Array<Node> = [startNode];
    const visiteds = new Set<string>([getId(startNode)]);

    while (queue.length) {
      const node = queue.shift();

      if (!node) {
        continue;
      }

      const isCheese = grid[node.rowIndex][node.colIndex];
      if (isCheese) {
        ++cheeseCount;
        grid[node.rowIndex][node.colIndex] = 0;

        continue;
      }

      positions.forEach(([rowIndex, colIndex]) => {
        const neighbor = {
          rowIndex: node.rowIndex + rowIndex,
          colIndex: node.colIndex + colIndex,
        };

        if (
          neighbor.rowIndex < 0 ||
          neighbor.colIndex < 0 ||
          neighbor.rowIndex > rowLastIndex ||
          neighbor.colIndex > colLastIndex
        ) {
          return;
        }

        const id = getId(neighbor);
        if (visiteds.has(getId(neighbor))) {
          return;
        }
        visiteds.add(id);

        queue.push(neighbor);
      });
    }

    return cheeseCount;
  };

  let time = 0;
  while (++time) {
    const cheeseCount = bfs({ startNode: { rowIndex: 0, colIndex: 0 } });
    const hasCheese = grid
      .map((cols) => {
        return cols.includes(1);
      })
      .includes(true);

    if (!hasCheese) {
      console.log(time, cheeseCount);

      break;
    }
  }
})();
