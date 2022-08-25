// (n-1) + n(m-1)

const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.on("line", (line) => {
  const [n, m] = line.split(" ").map((x) => parseInt(x));
  console.log(n - 1 + n * (m - 1));
  rl.close();
}).on("close", () => {
  process.exit(0);
});
