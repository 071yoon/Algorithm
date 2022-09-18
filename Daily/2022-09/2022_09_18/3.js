function solution(board, y, x) {
  let cpBoard = [];
  for (let i = 0; i < board.length; i++) {
    cpBoard.push([]);
    for (let j = 0; j < board[0].length; j++) {
      cpBoard[i].push(board[i][j]);
    }
  }
  if (board[y][x] === "M") {
    cpBoard[y][x] = "X";
    let retBoard = [];
    for (let i = 0; i < board.length; i++) {
      retBoard.push(cpBoard[i].join(""));
    }
    return retBoard;
  }
  let visit = [];
  for (let i = 0; i < cpBoard.length; i++) {
    visit.push([]);
    for (let j = 0; j < cpBoard[0].length; j++) {
      visit[i].push(false);
    }
  }
  let needVisit = [];
  needVisit.push([y, x]);
  visit[y][x] = true;
  let dy = [-1, -1, -1, 0, 0, 1, 1, 1];
  let dx = [-1, 0, 1, -1, 1, -1, 0, 1];
  while (needVisit.length) {
    let [ny, nx] = needVisit[0];
    needVisit.shift();
    let cnt = 0;
    for (let i = 0; i < 8; i++) {
      let nny = ny + dy[i];
      let nnx = nx + dx[i];
      if (
        nny < cpBoard.length &&
        nnx < cpBoard[0].length &&
        nny >= 0 &&
        nnx >= 0
      ) {
        if (!visit[nny][nnx] && cpBoard[nny][nnx] === "M") cnt++;
      } else {
        continue;
      }
    }
    if (cnt > 0) {
      cpBoard[ny][nx] = cnt.toString();
    } else {
      cpBoard[ny][nx] = "B";
      for (let i = 0; i < 8; i++) {
        let nny = ny + dy[i];
        let nnx = nx + dx[i];
        if (
          nny < cpBoard.length &&
          nnx < cpBoard[0].length &&
          nny >= 0 &&
          nnx >= 0
        ) {
          if (!visit[nny][nnx] && cpBoard[nny][nnx] === "E") {
            visit[nny][nnx] = true;
            needVisit.push([nny, nnx]);
          }
        }
      }
    }
  }
  let retBoard = [];
  for (let i = 0; i < board.length; i++) {
    retBoard.push(cpBoard[i].join("").replace(/M/g, "E"));
  }
  return retBoard;
}
