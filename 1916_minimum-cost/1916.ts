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

  class PriorityQueue<T = unknown> {
    private items: Array<T> = [];

    get isEmpty(): boolean {
      return this.size === 0;
    }

    get size(): number {
      return this.items.length;
    }

    constructor(private condition: (x: T, y: T) => boolean) {}

    top(): T | null {
      return this.items[0] ?? null;
    }

    push(n: T): void {
      this.items.push(n);
      this.bubbleUp();
    }

    pop(): T | null {
      if (this.size <= 1) {
        return this.items.pop() ?? null;
      }

      const max = this.items[0];
      this.sinkDown();

      return max;
    }

    private bubbleUp(): void {
      let currentIdx = this.size - 1;

      while (currentIdx > 0) {
        const parentIdx = Math.floor((currentIdx - 1) / 2);

        // 정렬 완료
        if (this.condition(this.items[parentIdx], this.items[currentIdx])) {
          break;
        }

        this.swap(parentIdx, currentIdx);
        currentIdx = parentIdx;
      }
    }

    private sinkDown(): void {
      const last = this.items.pop();
      if (!this.size || last === undefined) {
        return;
      }
      this.items[0] = last; // 제일 작은 원소를 첫 자리에 집어 넣는다.

      const lastIndex = this.size - 1;
      let currentIdx = 0;

      while (true) {
        let leftChildIdx = 2 * currentIdx + 1;
        let rightChildIdx = 2 * currentIdx + 2;
        let largestIdx = currentIdx;

        if (
          leftChildIdx <= lastIndex &&
          this.condition(this.items[leftChildIdx], this.items[largestIdx])
        ) {
          largestIdx = leftChildIdx;
        }

        if (
          rightChildIdx <= lastIndex &&
          this.condition(this.items[rightChildIdx], this.items[largestIdx])
        ) {
          largestIdx = rightChildIdx;
        }

        // 정렬 완료
        if (largestIdx === currentIdx) {
          break;
        }

        this.swap(currentIdx, largestIdx);
        currentIdx = largestIdx;
      }
    }

    private swap(i: number, j: number): void {
      [this.items[i], this.items[j]] = [this.items[j], this.items[i]];
    }
  }

  type Id = number;
  type Cost = number;
  interface Node {
    id: Id;
    cost: Cost;
  }
  type Graph = Map<Id, Map<Id, Cost>>;

  function dijkstra({
    vertexCount,
    graph,
    start,
    end,
  }: {
    vertexCount: number;
    graph: Graph;
    start: Id;
    end: Id;
  }): Cost {
    // 특정 노드로의 방문 비용
    const distance = new Array(vertexCount + 1).fill(Infinity);
    const minHeap = new PriorityQueue<Node>((x, y) => x.cost < y.cost);

    const startToStartCost = 0;
    distance[start] = startToStartCost;
    minHeap.push({ id: start, cost: startToStartCost });

    while (!minHeap.isEmpty) {
      const currentNode = minHeap.pop() as Node; // 가장 짧은 노드 추출

      if (currentNode.id === end) {
        return distance[end];
      }

      // 인접 노드 방문
      graph.get(currentNode.id)?.forEach((toNeighborCost, neighbor) => {
        const totalCost = distance[currentNode.id] + toNeighborCost;
        // 기존 코스트가 더 크다면 교체
        if (distance[neighbor] > totalCost) {
          distance[neighbor] = totalCost;
          minHeap.push({ id: neighbor, cost: totalCost });
        }
      });
    }

    return -1;
  }

  // solution
  const [[vertexCount], [edgeCount], ...inputs] = input
    .split('\n')
    .map((_input) => {
      return _input.split(' ').map((n) => parseInt(n));
    });

  const [edges, [start, end]] = [
    inputs.slice(0, -1),
    inputs.slice(inputs.length - 1, inputs.length)[0],
  ];

  const graph: Graph = edges.reduce((_graph, edge) => {
    const [vertex, neighbor, cost] = edge;

    const vertexToNeighbor = _graph.get(vertex) ?? new Map();
    vertexToNeighbor.set(neighbor, cost);
    _graph.set(vertex, vertexToNeighbor);

    return _graph;
  }, new Map());

  console.log(dijkstra({ vertexCount, graph, start, end }));
})();
