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

  const [[computerCount], [edgeCount], ...edges] = input
    .split('\n')
    .map((line) => {
      return line.split(' ').map((num) => {
        return parseInt(num);
      });
    });
  const computerCountWithBuffer = computerCount + 1;
  // console.log(computerCount, edgeCount, edges);

  const graph: Array<Set<number>> = Array.from(
    { length: computerCountWithBuffer },
    () => new Set()
  );
  edges.forEach(([a, b]) => {
    graph[a].add(b);
    graph[b].add(a);
  });

  const isVisiteds = new Array(computerCountWithBuffer).fill(false);
  let count = 0;

  const dfs = (index: number) => {
    isVisiteds[index] = true;

    graph[index].forEach((neighbor) => {
      if (isVisiteds[neighbor]) {
        return;
      }

      ++count;
      dfs(neighbor);
    });
  };
  dfs(1);

  console.log(count);
})();
