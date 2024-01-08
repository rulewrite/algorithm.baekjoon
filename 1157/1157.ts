// FIXME: 컴파일 에러가 나는데 원인을 모르겠다.
const input: string = (
  process.platform === 'linux'
    ? require('fs').readFileSync('/dev/stdin').toString()
    : 'a'
).trim();

// 데이터 전처리
const [lowerMin, lowerMax] = ['A'.charCodeAt(0), 'Z'.charCodeAt(0)];

const english = [...input.toUpperCase()].filter((c) => {
  const ascii = c.charCodeAt(0);

  return lowerMin <= ascii && ascii <= lowerMax;
});

// 문자 카운팅
const alphabetToCount = new Map<string, number>();

english.forEach((alphabet) => {
  alphabetToCount.set(alphabet, (alphabetToCount.get(alphabet) ?? 0) + 1);
});

// 최대 빈도 문자 구하기
const sorted = [...alphabetToCount.entries()].sort(([, aCount], [, bCount]) => {
  return bCount - aCount;
});

console.log(sorted[0][1] === sorted[1]?.[1] ? '?' : sorted[0][0]);
