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

  const lines = input.split('\n').map((line) => {
    return line.split(' ').map((n) => {
      return parseInt(n);
    }) as [number, number];
  });

  const [N, LENGTH] = lines[0];
  const result: Array<string> = [];
  const sequence: Array<number> = [];
  // console.log(N, LENGTH);

  const backtrack = () => {
    if (sequence.length === LENGTH) {
      result.push(sequence.join(' '));
      return;
    }

    for (let num = 1; num <= N; ++num) {
      if (sequence.includes(num)) {
        continue;
      }

      sequence.push(num);
      backtrack();
      sequence.pop();
    }
  };
  backtrack();

  console.log(result.join('\n'));
})();
