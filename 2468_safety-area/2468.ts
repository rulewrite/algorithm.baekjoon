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

  const [[LENGTH], ...grid] = input.split('\n').map((line) => {
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
  const lastIndex = LENGTH - 1;
  const bfs = ({
    startNode,
    visiteds,
    height,
  }: {
    startNode: Node;
    visiteds: Set<string>;
    height: number;
  }): void => {
    const queue: Array<Node> = [startNode];

    while (queue.length) {
      const node = queue.shift();

      if (!node) {
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
          neighbor.rowIndex > lastIndex ||
          neighbor.colIndex > lastIndex
        ) {
          return;
        }

        const id = getId(neighbor);
        if (visiteds.has(getId(neighbor))) {
          return;
        }
        visiteds.add(id);

        if (grid[neighbor.rowIndex][neighbor.colIndex] <= height) {
          return;
        }

        queue.push(neighbor);
      });
    }
  };

  const maxHeight = Math.max(...grid.map((cols) => Math.max(...cols)));
  // 컴파일 에러
  // const maxHeight = Math.max(...grid.flat());
  let maxSafeAreasCount = 0;
  for (let height = 0; height <= maxHeight; ++height) {
    const visiteds = new Set<string>();
    let safeAreaCount = 0;

    grid.forEach((cols, rowIndex) => {
      cols.forEach((areaHeight, colIndex) => {
        const node = { rowIndex, colIndex };

        const id = getId(node);
        if (visiteds.has(id)) {
          return;
        }
        visiteds.add(id);

        if (areaHeight <= height) {
          return;
        }

        ++safeAreaCount;
        bfs({ startNode: node, visiteds, height });
      });
    });

    maxSafeAreasCount = Math.max(maxSafeAreasCount, safeAreaCount);
  }

  console.log(maxSafeAreasCount);
})();
