#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int table[100][100] = {0,};
vector<int> answer;

void solution(vector<int> query, int mini){
  int x1 = query[0] - 1; int y1 = query[1] - 1;
  int x2 = query[2] - 1; int y2 = query[3] - 1;

  int tmp = table[x1][y1];
  // left
  for(int i = x1; i < x2; i++){
    table[i][y1] = table[i+1][y1];
    mini = min(mini, table[i][y1]);
  }
  // bottom
  for(int i = y1; i < y2; i++){
    table[x2][i] = table[x2][i+1];
    mini = min(mini, table[x2][i]);
  }
  // right
  for(int i = x2; i > x1; i--){
    table[i][y2] = table[i-1][y2];
    mini = min(mini, table[i][y2]);
  }
  // top
  for(int i = y2; i > y1; i--){
    table[x1][i] = table[x1][i-1];
    mini = min(mini, table[x1][i]);
  }
  table[x1][y1+1] = tmp;
  mini = min(mini, table[x1][y1+1]);
  answer.push_back(mini);
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < columns; j++){
      table[i][j] = i * columns + j + 1;
    }
  }
  for(int i = 0; i < queries.size(); i++){
    solution(queries[i], rows * columns);
  }
  return answer;
}
