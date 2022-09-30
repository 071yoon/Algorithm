let nth = "";

function solution(n, k) {
  let answer = 0;
  getNth(n, k);
  while (nth[nth.length - 1] === "0") {
    nth = nth.slice(0, -1);
  }
  let tmp = "";
  for (let i = 0; i < nth.length; i++) {
    if (nth[i] === "0") {
      if (isPrime(tmp)) {
        console.log(i);
        answer++;
      }
      tmp = "";
    } else if (i === nth.length - 1) {
      tmp += nth[i];
      if (isPrime(tmp)) {
        console.log(i);
        answer++;
      }
    } else {
      tmp += nth[i];
    }
  }
  console.log(nth);
  return answer;
}

function isPrime(tmp) {
  let numTmp = Number(tmp);
  if (numTmp <= 1) {
    return false;
  }
  let limit = Math.sqrt(numTmp);
  for (let i = 2; i <= limit; i++) {
    if (numTmp % i === 0) return false;
  }
  return true;
}

function getNth(n, k) {
  if (n > 0) {
    nth = (n % k).toString() + nth;
    getNth(Math.floor(n / k), k);
  }
}
