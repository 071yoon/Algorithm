#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
  int answer = 0;
  int newBoard[1010][1010] = {0};
  for(int i = 0; i < skill.size(); i++){
    int x1 = skill[i][1];
    int y1 = skill[i][2];
    int x2 = skill[i][3];
    int y2 = skill[i][4];
    int attack = (skill[i][0] == 1) ? -1 : 1;
    int damage = skill[i][5] * attack;
    newBoard[x1][y1] += damage;
    newBoard[x2+1][y2+1] += damage;
    newBoard[x1][y2+1] -= damage;
    newBoard[x2+1][y1] -= damage;
  }
  for(int i = 0; i < board.size() + 1; i++){
    for(int j = 0; j < board[0].size(); j++){
      newBoard[i][j+1] += newBoard[i][j];
    }
  }
  for(int j = 0; j < board[0].size() + 1; j++){
    for(int i = 0; i < board.size(); i++){
      newBoard[i+1][j] += newBoard[i][j];
    }
  }
  for(int i = 0; i < board.size(); i++){
    for(int j = 0; j < board[i].size(); j++){
      if(board[i][j] + newBoard[i][j]> 0){
        answer++;
      }
    }
  }
  return answer;
}