function solution(survey, choices) {
  var answer = "";
  let scores = [0, 0, 0, 0];
  let indexs = ["RT", "CF", "JM", "AN"];
  survey.map((item, i) => {
    if (item === "RT") {
      scores[0] += choices[i] - 4;
    } else if (item === "TR") {
      scores[0] += 4 - choices[i];
    } else if (item === "CF") {
      scores[1] += choices[i] - 4;
    } else if (item === "FC") {
      scores[1] += 4 - choices[i];
    } else if (item === "JM") {
      scores[2] += choices[i] - 4;
    } else if (item === "MJ") {
      scores[2] += 4 - choices[i];
    } else if (item === "AN") {
      scores[3] += choices[i] - 4;
    } else {
      scores[3] += 4 - choices[i];
    }
  });
  scores.map((score, index) => {
    if (score <= 0) {
      answer += indexs[index][0];
    } else {
      answer += indexs[index][1];
    }
  });
  return answer;
}
