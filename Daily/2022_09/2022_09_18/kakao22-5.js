function solution(id_list, report, k) {
  let reported = {};
  let result = {};
  id_list.forEach((id) => {
    reported[id] = new Set();
    result[id] = 0;
  });
  report.forEach((str) => {
    let data = str.split(" ");
    reported[data[1]].add(data[0]);
  });
  for (const person in reported) {
    if (reported[person].size >= k) {
      reported[person].forEach((item) => {
        result[item]++;
      });
    }
  }
  const answer = Object.values(result);
  return answer;
}
