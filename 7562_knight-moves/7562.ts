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

  const [_, ...cases] = input.split('\n').map((line) => {
    return line.split(' ').map((n) => parseInt(n));
  });

  interface Node {
    x: number;
    y: number;
  }

  const bfs = ({
    start,
    goal,
    boardSize,
  }: {
    start: Node;
    goal: Node;
    boardSize: number;
  }): number => {
    const visitedBoard = Array.from({ length: boardSize }, () => {
      return new Array(boardSize).fill(false);
    });
    const boardLastIndex = visitedBoard.length - 1;
    const queue = [{ node: start, step: 0 }];
    visitedBoard[start.y][start.x] = true;

    while (queue.length) {
      const item = queue.shift();
      if (!item) {
        continue;
      }

      const {
        step,
        node: { x, y },
      } = item;

      if (x === goal.x && y === goal.y) {
        return step;
      }

      const nextStep = item.step + 1;
      [
        { x: x - 1, y: y - 2 },
        { x: x + 1, y: y - 2 },
        { x: x + 2, y: y - 1 },
        { x: x + 2, y: y + 1 },
        { x: x + 1, y: y + 2 },
        { x: x - 1, y: y + 2 },
        { x: x - 2, y: y + 1 },
        { x: x - 2, y: y - 1 },
      ].forEach((neighbor) => {
        if (
          neighbor.x > boardLastIndex ||
          neighbor.y > boardLastIndex ||
          neighbor.x < 0 ||
          neighbor.y < 0 ||
          visitedBoard[neighbor.y][neighbor.x]
        ) {
          return;
        }

        visitedBoard[neighbor.y][neighbor.x] = true;
        queue.push({
          step: nextStep,
          node: neighbor,
        });
      });
    }

    return -1;
  };

  const result: Array<number> = [];
  while (cases.length) {
    const [[boardSize], start, goal] = cases.splice(0, 3);
    const startNode = {
      x: start[0],
      y: start[1],
    };
    const goalNode = {
      x: goal[0],
      y: goal[1],
    };

    result.push(
      bfs({
        start: startNode,
        goal: goalNode,
        boardSize,
      })
    );
  }

  console.log(result.join('\n'));
})();
