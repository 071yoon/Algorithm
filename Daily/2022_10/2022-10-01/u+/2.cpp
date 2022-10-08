#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
string org;

string solution(string compressed) {
  org = compressed;
  string answer = "";
  stack<pair<int, int> > st;
  for(int i = 0; i < compressed.length(); i++){
    if (compressed[i] >= '0' && compressed[i] <= '9'){
      int num = 0;
      while(compressed[i] >= '0' && compressed[i] <= '9'){
        num = num * 10 + compressed[i] - '0';
        i++;
      }
      st.push(make_pair(num, i));
    } 
    if (compressed[i] == ')'){
      int num = st.top().first;
      int idx = st.top().second + 1;
      int num_cnt = 0;
      int tmp_num = num;
      while(tmp_num){
        num_cnt++;
        tmp_num /= 10;
      }
      st.pop();
      string tmp = "";
      for(int j = idx; j < i; j++){
        tmp += compressed[j];
      }
      cout << tmp << "\n";
      string tmp2 = "";
      for(int j = 0; j < num; j++){
        tmp2 += tmp;
      }
      compressed.replace(idx - num_cnt, i - idx + num_cnt + 1, tmp2);
      // compressed.replace(idx - 1, i - idx + 2, tmp2);
      i = idx - num_cnt + tmp2.length() - 1;
    }
  }
  answer = compressed;
  // remove all numbers
  for(int i = 0; i < answer.length(); i++){
    if (answer[i] >= '0' && answer[i] <= '9'){
      answer.erase(i, 1);
      i--;
    }
  }
  return answer;
}