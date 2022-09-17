let cars = {};

function solution(fees, records) {
  var answer = [];
  records.map((item) => parsing(item, fees));
  let sortedKeys = [];
  sortedKeys = Object.keys(cars).sort();
  console.log(sortedKeys);
  for (let car in cars) {
    cal(cars[car], fees);
  }
  sortedKeys.map((key) => answer.push(cars[key].fee));
  return answer;
}

const cal = (car, fees) => {
  let timeConverted = 23 * 60 + 59;
  if (car.status === "IN") {
    car.finalTime += timeConverted - car.time;
  }
  car.finalTime -= fees[0];
  if (car.finalTime > 0) {
    car.fee += Math.ceil(car.finalTime / fees[2]) * fees[3];
  }
};

const parsing = (item, fees) => {
  let items = item.split(" ");
  let times = items[0].split(":");
  let timeConverted = Number(times[0]) * 60 + Number(times[1]);
  if (cars[items[1]] !== undefined) {
    if (items[2] === "OUT") {
      cars[items[1]].finalTime += timeConverted - cars[items[1]].time;
    } else {
      cars[items[1]].time = timeConverted;
    }
    cars[items[1]].status = items[2];
  } else {
    cars[items[1]] = {
      time: timeConverted,
      status: items[2],
      finalTime: 0,
      fee: fees[1],
    };
  }
};
