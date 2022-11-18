function solution(babbling) {
  let answer = 0;
  babbling.map((babble) => {
    const babbleCopy = babble;
    let tmp = "";
    let last = "";
    for (let i = 0; i < babbleCopy.length; i++) {
      tmp += babbleCopy[i];
      if (tmp === "aya" && last !== "aya") {
        last = "aya";
        tmp = "";
      } else if (tmp === "ye" && last !== "ye") {
        last = "ye";
        tmp = "";
      } else if (tmp === "woo" && last !== "woo") {
        last = "woo";
        tmp = "";
      } else if (tmp === "ma" && last !== "ma") {
        last = "ma";
        tmp = "";
      }
    }
    if (tmp === "") {
      answer += 1;
    }
  });
  return answer;
}
