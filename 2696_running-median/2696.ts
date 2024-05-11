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

    constructor(private condition: (x: number, y: number) => boolean) {}

    size(): number {
      return this.items.length;
    }

    top(): number | null {
      return this.items[0] ?? null;
    }

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
        if (this.condition(this.items[parentIdx], this.items[currentIdx])) {
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

  const chunk = (
    input: Array<unknown>,
    size: number
  ): Array<Array<unknown>> => {
    return input.reduce<Array<Array<unknown>>>((arr, element, index) => {
      if (index % size === 0) {
        return [...arr, [element]];
      }

      return [...arr.slice(0, -1), [...arr.slice(-1)[0], element]];
    }, []);
  };

  const inputs = input.split('\n');
  let caseCount = parseInt(inputs.shift() ?? '0');
  const result: Array<unknown> = [];

  while (caseCount--) {
    const sequenceCount = parseInt(inputs.shift() ?? '0');

    let sequence: Array<number> = [];

    while (sequenceCount !== sequence.length) {
      sequence = [
        ...sequence,
        ...(inputs.shift() ?? '').split(' ').map((n) => parseInt(n)),
      ];
    }

    // 중앙값 이하 (0이 중앙값)
    const leftMaxHeap = new PriorityQueue((x, y) => x > y);
    // 중앙값 초과
    const rightMinHeap = new PriorityQueue((x, y) => x < y);
    const medians: Array<number> = [];

    sequence.forEach((n, i) => {
      // 최대 힙이 중앙값을 포함하기에 같거나 하나 더 많다.
      if (leftMaxHeap.size() === rightMinHeap.size()) {
        leftMaxHeap.push(n);
      } else {
        rightMinHeap.push(n);
      }

      const [leftTop, rightTop] = [leftMaxHeap.top(), rightMinHeap.top()];

      if (
        rightTop !== null &&
        leftTop !== null &&
        // 왼쪽 최대 수가 오른쪽 최소 수보다 클 경우 교환
        leftTop > rightTop
      ) {
        rightMinHeap.push(leftTop);
        leftMaxHeap.pop();
        leftMaxHeap.push(rightTop);
        rightMinHeap.pop();
      }

      const isEven = (i + 1) % 2 === 0;
      if (isEven) {
        return;
      }

      const median = leftMaxHeap.top();
      median !== null && medians.push(median);
    });

    result.push(medians.length);
    chunk(medians, 10).forEach((a) => {
      result.push(a.join(' '));
    });
  }

  console.log(result.join('\n'));
})();
