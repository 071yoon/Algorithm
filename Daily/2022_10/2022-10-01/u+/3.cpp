#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int row;
int col;
char dirs[4] = {'E', 'W', 'S', 'N'};
vector<string> train;
vector<string> org;
string board[4] = {"0000", "0000", "0000", "0000"};

void print(){
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      cout << board[i][j];
    }
    cout << "\n";
  }
  cout << "\n";
}

bool okay(int x, int y, char target) {
  if (target == 'W'){
    if (y - 1 < 0) return true;
    else if (board[x][y - 1] == 'E') return false;
    else return true;
  } else if (target == 'N'){
    if (x - 1 < 0) return true;
    else if (board[x-1][y] == 'S') return false;
    else return true;
  } else {
    return true;
  }
}

int ans = 100;

void fill(int index){
  if(index == row * col){
    int tmp = 0;
    for(int i = 0; i < row; i++){
      for(int j = 0; j < col; j++){
        if (org[i][j] != board[i][j]) tmp++;
      }
    }
    ans = min(ans, tmp);
    return ;
  } else {
    int x = index / col;
    int y = index % col;
    for(int i = 0; i < 4; i++){
      if (okay(x, y, dirs[i])){
        board[x][y] = dirs[i];
        // cout << board[x][y];
        fill(index + 1);
      }
    }
  }
}

int solution(vector<string> train) {
  row = train.size();
  col = train[0].size();
  org = train;
  fill(0);
  // cout << ans << "\n";
  return ans;
}

// int main(){
//   train.push_back("EE");
//   train.push_back("EE");
//   // train.push_back("NNW");
//   // train.push_back("NNN");
//   solution(train);
// }