function solution(info, query) {
  var answer = [];
  const infos = info.map((v) => v.split(" "));
  const queries = query.map((v) => v.split(" and "));
  queries.forEach((q) => {
    const lang = q[0];
    const job = q[1];
    const career = q[2];
    const [food, score] = q[3].split(" ");
    // console.log(lang, job, career, food, score);
    const filtered = infos.filter((v) => {
      if (lang !== "-" && v[0] !== lang) return false;
      if (job !== "-" && v[1] !== job) return false;
      if (career !== "-" && v[2] !== career) return false;
      if (food !== "-" && v[3] !== food) return false;
      return Number(v[4]) >= Number(score);
    });
    // console.log(filtered);
    answer.push(filtered.length);
  });
  return answer;
}
