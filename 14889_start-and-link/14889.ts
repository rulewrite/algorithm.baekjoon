(() => {
  type Index = number;

  const isBaekjoon = process.platform === 'linux';
  const input: string = require('fs')
    .readFileSync(
      isBaekjoon
        ? '/dev/stdin'
        : require('path').resolve(__dirname, 'example.txt')
    )
    .toString()
    .trim();

  const [[N], ...scores] = input.split('\n').map((line) => {
    return line.split(' ').map((n) => parseInt(n));
  });
  // console.log(scores, '\n-------');

  const teamCount = N / 2;
  const invites = new Set<Index>();

  let minScore = Infinity;
  const setScore = () => {
    const teams: [Array<Index>, Array<Index>] = [[], []];

    for (let i = 0; i < N; ++i) {
      teams[Number(invites.has(i))].push(i);
    }

    const teamScores = teams.map((team) => {
      return team.reduce((acc1, index1) => {
        return team.reduce((acc2, index2) => {
          if (index1 === index2) {
            return acc2;
          }

          return acc2 + scores[index1][index2];
        }, acc1);
      }, 0);
    });

    minScore = Math.min(Math.abs(teamScores[0] - teamScores[1]), minScore);
  };

  const backtrack = () => {
    if (invites.size === teamCount) {
      // console.log(invites);
      setScore();
      return;
    }

    for (let j = 0; j < N; ++j) {
      if (invites.has(j)) {
        continue;
      }

      invites.add(j);
      backtrack();
      invites.delete(j);
    }
  };

  for (let i = 0; i < N; ++i) {
    invites.add(i);
    backtrack();
    invites.delete(i);
  }

  console.log(minScore);
})();
