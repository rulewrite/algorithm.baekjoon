const isBaekjoon = process.platform === 'linux';
const input: string = require('fs')
  .readFileSync(
    isBaekjoon
      ? '/dev/stdin'
      : require('path').resolve(__dirname, 'example.txt')
  )
  .toString()
  .trim();

const lines = input.split('\n').map((line) => {
  return line.split(' ').map((n) => {
    return parseInt(n);
  }) as [number, number];
});

class Graph {
  nodeToNeighbors: Map<number, Set<number>> = new Map();

  constructor(nodeCount: number) {
    for (let i = 1; i <= nodeCount; ++i) {
      this.addNode(i);
    }
  }

  addNode(node: number): void {
    if (this.nodeToNeighbors.has(node)) {
      return;
    }

    this.nodeToNeighbors.set(node, new Set());
  }

  addEdge(toNode: number, fromNode: number): void {
    const toNodeNeighbors = this.nodeToNeighbors.get(toNode);
    const fromNodeNeighbors = this.nodeToNeighbors.get(fromNode);

    if (!toNodeNeighbors || !fromNodeNeighbors) {
      return;
    }

    toNodeNeighbors.add(fromNode);
    fromNodeNeighbors.add(toNode);
  }
}

const [[nodeCount], ...edges] = lines;
const graph = new Graph(nodeCount);
edges.forEach(([u, v]) => {
  graph.addEdge(u, v);
});

const isVisiteds = new Array(graph.nodeToNeighbors.size + 1).fill(false);

const dfs = (node: number) => {
  isVisiteds[node] = true;

  graph.nodeToNeighbors.get(node)?.forEach((neighbor) => {
    if (isVisiteds[neighbor]) {
      return;
    }

    dfs(neighbor);
  });
};

let count = 0;
graph.nodeToNeighbors.forEach((_, node) => {
  if (isVisiteds[node]) {
    return;
  }

  dfs(node);
  ++count;
});

console.log(count);
