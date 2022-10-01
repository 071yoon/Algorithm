#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

map <string, bool[1000000]> m;

string solution(vector<string> registered_list, string new_id) {
  string answer = "";
  string my_id = "";
  int new_no = 0;

  for(int i = 0; i < new_id.length(); i++){
    if (new_id[i] >= '0' && new_id[i] <= '9'){
      while(new_id[i] >= '0' && new_id[i] <= '9'){
        new_no = new_no * 10 + new_id[i] - '0';
        i++;
      }
      break ;
    }
    my_id += new_id[i];
  }

  for(int i = 0; i < registered_list.size(); i++){
    string tmp = "";
    int no = 0;
    bool flag = 0;
    for(int j = 0; j < registered_list[i].length(); j++){
      if (registered_list[i][j] >= '0' && registered_list[i][j] <= '9'){
        while(registered_list[i][j] >= '0' && registered_list[i][j] <= '9'){
          no = no * 10 + registered_list[i][j] - '0';
          j++;
        }
        break ;
      }
      if(registered_list[i][j] != my_id[j]){
        flag = 1;
        break;
      }
      tmp += registered_list[i][j];
    }
    if (flag) continue;
    m[tmp][no] = true;
  }

  if(m.find(my_id) == m.end()){
    answer = my_id;
  } else {
    if(m[my_id][new_no] == false){
      if(new_no == 0){
        answer = my_id;
        return answer;
      }
      answer = my_id + to_string(new_no);
    } else {
      for(int i = new_no; i < 1000000; i++){
        if(m[my_id][i] == false){
          if(i == 0){
            answer = my_id;
            return answer;
          }
          answer = my_id + to_string(i);
          break ;
        }
      }
    }
  }
  return answer;
}