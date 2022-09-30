#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
  int zero = 0;
  int cor = 0;
  for(int i = 0; i < lottos.size(); i++){
    if(lottos[i] == 0){
      zero++;
      continue;
    }
    for(int j = 0; j < win_nums.size(); j++){
      if(lottos[i] == win_nums[j]){
        cor++;
      }
    }
  }
  cout << zero << "\n" << cor << "\n";

  vector<int> answer;
  int worst = 7 - cor;
  int best = 7 - (cor + zero);
  if (worst == 7) worst = 6;
  if (best == 7) best = 6;
  answer.push_back(best);
  answer.push_back(worst);
  return answer;
}