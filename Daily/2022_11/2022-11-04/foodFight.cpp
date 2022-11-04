#include <string>
#include <vector>

using namespace std;
string answer = "";

void backTrack(int limit, int cur, vector<int> &food) {
  if (limit == cur) {
    answer += "0";
    return ;
  }
  for(int i = 0; i < food[cur] / 2; i++){
    answer += to_string(cur);
  }
  backTrack(limit, cur + 1, food);
  for(int i = 0; i < food[cur] / 2; i++){
    answer += to_string(cur);
  }
}

string solution(vector<int> food) {
  backTrack(food.size(), 1, food);
  return answer;
}