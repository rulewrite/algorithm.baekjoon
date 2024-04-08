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

  const [_, [startNode, endNode], __, ...edges] = input
    .split('\n')
    .map((line) => {
      return line.split(' ').map((n) => parseInt(n));
    });

  const graph = new Map<number, Set<number>>();
  edges.forEach(([a, b]) => {
    if (!graph.has(a)) {
      graph.set(a, new Set());
    }
    if (!graph.has(b)) {
      graph.set(b, new Set());
    }

    graph.get(a)?.add(b);
    graph.get(b)?.add(a);
  });
  // console.log(graph, '\n-------');

  const bfs = ({
    startNode,
    endNode,
  }: {
    startNode: number;
    endNode: number;
  }): number => {
    const isVisiteds = new Set<number>();
    const queue = [{ id: startNode, level: 0 }];

    while (queue.length) {
      // console.log(queue);
      const node = queue.shift();
      if (!node) {
        continue;
      }

      isVisiteds.add(node.id);

      if (node.id === endNode) {
        return node.level;
      }

      const nextLevel = node.level + 1;
      graph.get(node.id)?.forEach((neighbor) => {
        if (isVisiteds.has(neighbor)) {
          return;
        }

        queue.push({ id: neighbor, level: nextLevel });
      });
    }

    return -1;
  };

  console.log(bfs({ startNode, endNode }));
})();
