const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.on("line", (line) => {
  const [songs, mid] = line.split(" ").map((x) => parseInt(x));
  console.log(songs * (mid - 1) + 1);
  rl.close();
}).on("close", () => {
  process.exit(0);
});
