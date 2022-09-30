let fails = new Set();
let success = new Set();

function solution(orders) {
  const win = Math.ceil(orders[0].length / 2);
  for (let times = 0; times < orders.length; times++) {
    let trial = {};
    for (let time = 0; time < orders.length; time++) {
      for (let people = 0; people < orders.length; people++) {
        if (fails.has(orders[time][people].toString())) {
          continue;
        } else if (trial[orders[time][people]] !== undefined) {
          trial[orders[time][people]]++;
        } else {
          trial[orders[time][people]] = 1;
        }
        break;
      }
    }
    for (const person in trial) {
      if (trial[person] >= win) {
        success.add(person);
      }
    }
    if (success.size) {
      const successArr = Array.from(success);
      successArr.sort();
      return [times + 1, Number(successArr[success.size - 1])];
    } else {
      let sortable = [];
      for (let person in trial) {
        sortable.push([person, trial[person]]);
      }
      sortable.sort(function (a, b) {
        if (a[1] === b[1]) {
          return a[0] - b[0];
        }
        return a[1] - b[1];
      });
      for (let sorta = 0; sorta < sortable.length; sorta++) {
        if (fails.has(sortable[sorta][0])) {
          continue;
        } else {
          fails.add(sortable[sorta][0]);
          break;
        }
      }
    }
  }
}
