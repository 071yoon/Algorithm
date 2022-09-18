function solution(students) {
  var answer = [];
  var scores = [];
  students.forEach((student, index) => {
    let a = (student.match(/A/g) || []).length;
    let l = (student.match(/L/g) || []).length;
    let p = (student.match(/P/g) || []).length;
    p += Math.floor(l / 2);
    if (p >= 3) {
      scores.push([index + 1, 0]);
    } else {
      scores.push([index + 1, 10 + a - p]);
    }
  });
  scores.sort((a, b) => b[1] - a[1]);
  scores.map((score) => score[0]);
  console.log(scores);
  return answer;
}
