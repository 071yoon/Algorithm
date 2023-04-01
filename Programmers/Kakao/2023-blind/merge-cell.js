function solution(commands) {
  let data = [];
  var answer = [];
  let merge = [];

  for (let i = 0; i < 52; i++) {
    let row = [];
    let data_row = [];
    for (let j = 0; j < 52; j++) {
      row.push({ r: i, c: j });
      data_row.push("EMPTY");
    }
    data.push(data_row);
    merge.push(row);
  }

  commands.map((command) => {
    const singleCommand = command.split(" ");
    if (singleCommand[0] === "UPDATE") {
      // 위치 줬을 때
      if (singleCommand.length === 4) {
        const { r, c } = merge[singleCommand[1]][singleCommand[2]];
        data[r][c] = singleCommand[3];
        // data[singleCommand[1]][singleCommand[2]] = singleCommand[3];
      } else {
        // 값으로 수정
        for (let i = 0; i < 52; i++) {
          for (let j = 0; j < 52; j++) {
            if (data[i][j] === singleCommand[1]) {
              data[i][j] = singleCommand[2];
            }
          }
        }
      }
    } else if (singleCommand[0] === "MERGE") {
      // 같을 때
      if (
        singleCommand[1] === singleCommand[3] &&
        singleCommand[2] === singleCommand[4]
      )
        return;
      const { r: r1, c: c1 } = merge[singleCommand[1]][singleCommand[2]];
      const { r: r2, c: c2 } = merge[singleCommand[3]][singleCommand[4]];

      if (data[r1][c1] === "EMPTY") data[r1][c1] = data[r2][c2];
      for (let i = 0; i < 52; i++) {
        for (let j = 0; j < 52; j++) {
          if (merge[i][j].r === r2 && merge[i][j].c === c2) {
            merge[i][j].r = r1;
            merge[i][j].c = c1;
          }
        }
      }
    } else if (singleCommand[0] === "UNMERGE") {
      const { r, c } = merge[singleCommand[1]][singleCommand[2]];
      tmp = data[r][c];
      for (let i = 0; i < 52; i++) {
        for (let j = 0; j < 52; j++) {
          if (merge[i][j].r === r && merge[i][j].c === c) {
            merge[i][j] = { r: i, c: j };
            data[i][j] = "EMPTY";
          }
        }
      }
      data[singleCommand[1]][singleCommand[2]] = tmp;
    } else if (singleCommand[0] === "PRINT") {
      const { r, c } = merge[singleCommand[1]][singleCommand[2]];
      answer.push(data[r][c]);
    }
  });
  return answer;
}
