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

  class PriorityQueue {
    private items: Array<number> = [];

    constructor() {}

    push(n: number): void {
      this.items.push(n);
      this.bubbleUp();
    }

    pop(): number | null {
      if (this.items.length <= 1) {
        return this.items.pop() ?? null;
      }

      const max = this.items[0];
      this.sinkDown();

      return max;
    }

    private bubbleUp(): void {
      let currentIdx = this.items.length - 1;

      while (currentIdx > 0) {
        const parentIdx = Math.floor((currentIdx - 1) / 2);

        // 정렬 완료
        if (this.items[parentIdx] >= this.items[currentIdx]) {
          break;
        }

        this.swap(parentIdx, currentIdx);
        currentIdx = parentIdx;
      }
    }

    private sinkDown(): void {
      const last = this.items.pop();
      if (!this.items.length || last === undefined) {
        return;
      }
      this.items[0] = last; // 제일 작은 원소를 첫 자리에 집어 넣는다.

      const lastIndex = this.items.length - 1;
      let currentIdx = 0;

      while (true) {
        let leftChildIdx = 2 * currentIdx + 1;
        let rightChildIdx = 2 * currentIdx + 2;
        let largestIdx = currentIdx;

        if (
          leftChildIdx <= lastIndex &&
          this.items[leftChildIdx] > this.items[largestIdx]
        ) {
          largestIdx = leftChildIdx;
        }

        if (
          rightChildIdx <= lastIndex &&
          this.items[rightChildIdx] > this.items[largestIdx]
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

  const [, ...inputs] = input.split('\n').map((n) => parseInt(n));

  const priorityQueue = new PriorityQueue();
  const result: Array<number> = [];
  inputs.forEach((n) => {
    if (n === 0) {
      result.push(priorityQueue.pop() ?? 0);

      return;
    }

    priorityQueue.push(n);
  });

  console.log(result.join('\n'));
})();
