#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 빵 야채 고기
// 1 2 3 1 순서

int solution(vector<int> ingredient) {
  int answer = 0;
  for(int i = 3; i < ingredient.size(); i++){
    if(ingredient[i] == 1 && ingredient[i-1] == 3 && ingredient[i-2] == 2 && ingredient[i-3] == 1){
      answer++;
      ingredient.erase(ingredient.begin() + i);
      ingredient.erase(ingredient.begin() + i - 1);
      ingredient.erase(ingredient.begin() + i - 2);
      ingredient.erase(ingredient.begin() + i - 3);
      i -= 4;
    }
  }
  return answer;
}