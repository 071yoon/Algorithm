const arr = [];
for (let i = 0; i < existingFolders.length; i++) {
  if (existingFolders[i].includes("New Folder")) {
    const splited = existingFolders[i].split("New Folder");
    if (splited[0] || splited[2]) continue;
    if (!splited[1]) {
      arr.push(1);
      continue;
    }
    const leftNum = splited[1].split("(");
    if (leftNum[0] !== " ") continue;
    const rightNum = leftNum[1].split(")");
    if (rightNum[1]) continue;
    let flag = 0;
    for (let j = 0; j < rightNum[0].lenght; j++) {
      if (rightNum[0][j] < "0" || rightNum[0][j] > "9") {
        flag = 1;
        break;
      }
    }
    if (flag) continue;
    arr.push(rightNum[0]);
  }
}
arr.sort();
if (arr.length === 0) return "New Folder";
let prev = arr[0];
for (let i = 1; i < arr.length; i++) {
  let cur = arr[i];
  if (cur === prev + 1) {
    continue;
  }
  const num = prev + 1;
  return "New Folder (" + num + ")";
}
