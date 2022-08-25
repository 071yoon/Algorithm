const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let cnt = 0;
let times = [];
let leftTime;

rl.on("line", (line) => {
  if (cnt === 0) {
    times = line.split(" ").map((x) => parseInt(x));
    cnt++;
  } else {
    leftTime = parseInt(line);
    rl.close();
  }
}).on("close", () => {
  const total = times[0] * 3600 + times[1] * 60 + times[2];
  leftTime += total;
  const hr = Math.floor(leftTime / 3600);
  const min = Math.floor((leftTime - hr * 3600) / 60);
  const sec = leftTime - hr * 3600 - min * 60;
  console.log((hr % 24) + " " + min + " " + sec);
  process.exit(0);
});
