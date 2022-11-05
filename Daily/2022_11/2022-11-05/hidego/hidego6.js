var trade = JSON.parse(dayTrade);
let people = {};
for (let i = 0; i < trade.length; i++) {
  if (people[trade[i]["user"]]) {
    people[trade[i]["user"]] += Number(trade[i].countOfStocks);
  } else {
    people[trade[i]["user"]] = Number(trade[i].countOfStocks);
  }
}
let peopleArr = [];
for (let key in people) {
  peopleArr.push([key, people[key]]);
}
peopleArr.sort((a, b) => b[1] - a[1]);
for (let i = 0; i < peopleArr.length; i++) {
  console.log(`${peopleArr[i][0]} : ${peopleArr[i][1]}`);
}
let res = [];
let start = (pageNumber - 1) * pageSize;
let end = start + pageSize;
for (let i = start; i < end; i++) {
  if (peopleArr[i]) {
    res.push({ user: peopleArr[i][0], totalStocks: peopleArr[i][1] });
  }
}
return res;
