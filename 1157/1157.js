const input = (
  process.platform === 'linux'
    ? require('fs').readFileSync('/dev/stdin').toString()
    : 'Mississipi'
).trim();

// 데이터 전처리
const [lowerMin, lowerMax] = ['A'.charCodeAt(0), 'Z'.charCodeAt(0)];
const [upperMin, upperMax] = ['a'.charCodeAt(0), 'z'.charCodeAt(0)];

const english = [...input]
  .filter((_, index) => {
    const ascii = input.charCodeAt(index);

    return (
      (lowerMin <= ascii && ascii <= lowerMax) ||
      (upperMin <= ascii && ascii <= upperMax)
    );
  })
  .map((alphabet) => {
    return alphabet.toUpperCase();
  });

// 문자 카운팅
const alphabetToCount = new Map();

english.forEach((alphabet) => {
  alphabetToCount.set(alphabet, (alphabetToCount.get(alphabet) ?? 0) + 1);
});

// 최대 빈도 문자 구하기
const [[firstAlphabet, firstCount], [, secondCount]] = [
  ...alphabetToCount.entries(),
].sort(([, aCount], [, bCount]) => {
  return bCount - aCount;
});

console.log(firstCount === secondCount ? '?' : firstAlphabet);
