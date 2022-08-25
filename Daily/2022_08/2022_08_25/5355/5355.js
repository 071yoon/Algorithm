const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let cnt = -1;
let counter = 0;

rl.on("line", (line) => {
  if (cnt === -1) {
    cnt = parseInt(line);
  } else if (counter < cnt) {
    counter++;
    const data = line.split(" ");
    let result = Number(data[0]);
    for (let i = 1; i < data.length; i++) {
      if (data[i] === "@") {
        result *= 3;
      } else if (data[i] === "%") {
        result += 5;
      } else if (data[i] === "#") {
        result -= 7;
      }
    }
    console.log(result.toFixed(2));
  } else {
    rl.close();
  }
}).on("close", () => {
  process.exit(0);
});
