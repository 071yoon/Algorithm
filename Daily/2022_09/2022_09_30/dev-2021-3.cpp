#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, string> parent;
map<string, int> money;
vector<int> answer;

void solve(string seller, int amount){
  if(seller == "-") return;
  int fee = amount * 0.1;
  money[seller] += amount - fee;
  if (fee < 1) return;
  solve(parent[seller], fee);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
  for(int i = 0; i < enroll.size(); i++){
    parent[enroll[i]] = referral[i];
    money[enroll[i]] = 0;
  }
  for(int i = 0; i < seller.size(); i++){
    solve(seller[i], amount[i] * 100);
  }
  for(int i = 0; i < enroll.size(); i++){
    answer.push_back(money[enroll[i]]);
  }
  return answer;
}