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

  const [[, , startNode], ...edges] = input.split('\n').map((line) => {
    return line.split(' ').map((n) => parseInt(n));
  });

  const graph = new Map<number, Array<number>>();
  edges.forEach(([a, b]) => {
    if (!graph.has(a)) {
      graph.set(a, []);
    }
    if (!graph.has(b)) {
      graph.set(b, []);
    }

    graph.get(a)?.push(b);
    graph.get(b)?.push(a);
  });
  // console.log(graph, '\n-------');

  const dfs = (startNode: number): Array<number> => {
    const stack: Array<number> = [startNode];
    const isVisiteds = new Set<number>();
    const orders: Array<number> = [];

    while (stack.length) {
      // console.log(stack);
      const node = stack.pop();
      if (!node) {
        continue;
      }

      if (isVisiteds.has(node)) {
        continue;
      }

      orders.push(node);
      isVisiteds.add(node);
      stack.push(...(graph.get(node) ?? []));
    }

    return orders;
  };

  const bfs = (startNode: number): Array<number> => {
    const queue: Array<number> = [startNode];
    const isVisiteds = new Set<number>();
    const orders: Array<number> = [];

    while (queue.length) {
      // console.log(queue);
      const node = queue.shift();
      if (!node) {
        continue;
      }

      if (isVisiteds.has(node)) {
        continue;
      }

      orders.push(node);
      isVisiteds.add(node);
      queue.push(...(graph.get(node) ?? []));
    }

    return orders;
  };

  graph.forEach((neighbors) => {
    neighbors.sort((a, b) => b - a);
  });
  const dfsOrders = dfs(startNode);

  graph.forEach((neighbors) => {
    neighbors.sort((a, b) => a - b);
  });
  const bfsOrders = bfs(startNode);

  console.log(
    [dfsOrders, bfsOrders]
      .map((orders) => {
        return orders.join(' ');
      })
      .join('\n')
  );
})();
