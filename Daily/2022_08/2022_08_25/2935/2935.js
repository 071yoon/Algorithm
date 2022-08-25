const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let count = 0;
let a,
  b = 0;
let char = "";

rl.on("line", (line) => {
  if (count == 0) {
    count += 1;
    a = parseInt(line);
  } else if (count == 1) {
    count += 1;
    char = line;
  } else if (count == 2) {
    count += 1;
    b = parseInt(line);
  } else {
    rl.close();
  }
}).on("close", () => {
  if (char == "*") {
    console.log((a * b).toString());
  } else {
    console.log(a + b);
  }
  process.exit(0);
});
