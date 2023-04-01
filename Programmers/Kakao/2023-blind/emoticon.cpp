#include <iostream>
#include <string>
#include <vector>

using namespace std;

int emoticon_size = 0;
vector<vector<int>> users_copy;
vector<int> emoticons_copy;
int answer_first;
int answer_second;
vector<int> answer;
vector<int> sale_percent;

void back_tracking(int current) {
  if (current == emoticon_size) {
    int tmp_answer_first = 0;
    int tmp_answer_second = 0;
    // 한명씩 계산
    for (int user = 0; user < users_copy.size(); user++) {
      int total_value = 0;
      // 이모티콘 하나씩 계산
      for (int emt = 0; emt < emoticon_size; emt++) {
        if (sale_percent[emt] >= users_copy[user][0]) {
          total_value += emoticons_copy[emt] -
                         (emoticons_copy[emt] * sale_percent[emt] * 0.01);
        }
      }
      if (total_value >= users_copy[user][1]) {
        tmp_answer_first += 1;
      } else {
        tmp_answer_second += total_value;
      }
    }
    if (tmp_answer_first == answer_first) {
      if (tmp_answer_second > answer_second) {
        answer_second = tmp_answer_second;
      }
    } else if (tmp_answer_first > answer_first) {
      answer_first = tmp_answer_first;
      answer_second = tmp_answer_second;
    }
    return;
  }
  for (int i = 1; i <= 4; i++) {
    sale_percent[current] = i * 10;
    back_tracking(current + 1);
  }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
  users_copy = users;
  emoticons_copy = emoticons;
  emoticon_size = emoticons.size();
  answer_first = 0;
  answer_second = 0;
  for (int i = 0; i < emoticon_size; i++) {
    sale_percent.push_back(0);
  }
  back_tracking(0);
  answer.push_back(answer_first);
  answer.push_back(answer_second);
  return answer;
}