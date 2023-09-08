function solution(name, yearning, photo) {
  var answer = [];
  let nameYearning = {};
  for (let i = 0; i < name.length; i++) {
    nameYearning[name[i]] = yearning[i];
  }
  for (let i = 0; i < photo.length; i++) {
    let score = 0;
    for (let j = 0; j < photo[i].length; j++) {
      if (nameYearning[photo[i][j]] !== undefined) {
        score += nameYearning[photo[i][j]];
      }
    }
    answer.push(score);
  }
  return answer;
}
