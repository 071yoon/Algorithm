#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

set<string> s;

void checkFreq(int num){
  string str_tmp = "0000000000";
  while(num > 0){
    str_tmp[num % 10]++;
    num /= 10;
  }
  s.insert(str_tmp);
}

int solution(vector<int> arr) {
    int answer = 0;
    for(int i = 0; i < arr.size(); i++){
      checkFreq(arr[i]);
    }
    answer = s.size();
    return answer;
}