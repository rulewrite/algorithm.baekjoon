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

  const [firstLine, ...lines] = input.split('\n');
  const [rowCount, colCount] = firstLine.split(' ').map((n) => parseInt(n));
  const maze = lines.map((line) => {
    return line.split('').map((n) => parseInt(n));
  });
  const xLastIndex = colCount - 1;
  const yLastIndex = rowCount - 1;
  // console.log(maze);

  interface Node {
    x: number;
    y: number;
  }

  const getId = (node: Node): string => {
    return `${node.x},${node.y}`;
  };

  const bfs = ({ start, goal }: { start: Node; goal: Node }): number => {
    const isVisiteds = new Set<string>();
    const queue = [
      {
        node: start,
        step: 1,
      },
    ];

    while (queue.length) {
      const item = queue.shift();
      if (!item) {
        continue;
      }

      const { node, step } = item;
      const { x, y } = node;

      if (x === goal.x && y === goal.y) {
        return step;
      }

      const nextStep = step + 1;
      // 상하좌우
      [
        { x, y: Math.max(y - 1, 0) },
        { x, y: Math.min(y + 1, yLastIndex) },
        { x: Math.max(x - 1, 0), y },
        { x: Math.min(x + 1, xLastIndex), y },
      ].forEach((neighbor) => {
        const neighborId = getId(neighbor);

        if (isVisiteds.has(neighborId)) {
          return;
        }
        isVisiteds.add(neighborId);

        if (!maze[neighbor.y][neighbor.x]) {
          return;
        }

        queue.push({ node: neighbor, step: nextStep });
      });
    }

    return -1;
  };

  console.log(
    bfs({
      start: {
        x: 0,
        y: 0,
      },
      goal: {
        x: xLastIndex,
        y: yLastIndex,
      },
    })
  );
})();
