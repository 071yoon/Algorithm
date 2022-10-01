#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int visited[1000][1000] = {0, };
int row, col;
vector<string> board;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int countries[26] = {0, };
int all_countries[26] = {0, };
int maxi = 0;
int win_country = 0;

void dfs(int x, int y){
  visited[x][y] = 1;
  countries[board[x][y] - 'A']++;
  maxi = max(maxi, countries[board[x][y] - 'A']);
  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 0 && nx < row && ny >= 0 && ny < col){
      if (board[nx][ny] != '.' && !visited[nx][ny]){
        dfs(nx, ny);
      }
    }
  }
}

int solution(vector<string> maps) {
  row = maps.size();
  col = maps[0].size();
  board = maps;
  for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
      if(maps[i][j] != '.' && !visited[i][j]){
        maxi = 0;
        for(int k = 0; k < 26; k++){
          countries[k] = 0;
        }
        dfs(i, j); // check continent
        for(int i = 25; i >= 0; i--){
          if (countries[i] == maxi){
            win_country = i;
            break;
          }
        }
        for(int i = 0; i < 26; i++){
          if (countries[i] < countries[win_country]){
            all_countries[win_country] += countries[i];
          } else {
            all_countries[i] += countries[i];
          }
        }
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < 26; i++){
    ans = max(ans, all_countries[i]);
  }
  return ans;
}

int main(){
  vector<string> maps;
  maps.push_back("AABCA.QA");
  maps.push_back("AABC..QX");
  maps.push_back("BBBC.Y..");
  maps.push_back(".A...T.A");
  maps.push_back("....EE..");
  maps.push_back(".M.XXEXQ");
  maps.push_back("KL.TBBBQ");
  solution(maps);
}