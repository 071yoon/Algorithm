#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string convert_to_binary(long long number) {
  string tmp;
  long long tmp_number = number;
  while (tmp_number) {
    if (tmp_number % 2) {
      tmp.append("1");
    } else {
      tmp.append("0");
    }
    tmp_number /= 2;
  }
  reverse(tmp.begin(), tmp.end());
  return tmp;
}

bool check_odd_deep(string bin, bool bef) {
  if (bin.size() == 1) {
    if (bin[0] == '1' && !bef) return false;
    return true;
  }
  int mid = bin.size() / 2;
  if (bin[mid] == '1') {
    if (!bef) return false;
    bool left_checker = check_odd_deep(bin.substr(0, mid), true);
    bool right_checker = check_odd_deep(bin.substr(mid + 1), true);
    return left_checker && right_checker;
  } else {
    bool left_checker = check_odd_deep(bin.substr(0, mid), false);
    bool right_checker = check_odd_deep(bin.substr(mid + 1), false);
    return left_checker && right_checker;
  }
}

bool check_odd(string &bin) {
  string bin_copy = bin;
  int bin_sz = bin_copy.size();
  int mid = bin_sz / 2;
  if (bin_copy[bin_sz / 2] == '0') {
    return false;
  }
  if (bin_sz == 1 && bin_copy[0] == '1') return true;
  bool left_checker = check_odd_deep(bin_copy.substr(0, mid), true);
  bool right_checker = check_odd_deep(bin_copy.substr(mid + 1), true);
  return left_checker && right_checker;
}

vector<int> solution(vector<long long> numbers) {
  vector<int> answer;
  for (int i = 0; i < numbers.size(); i++) {
    string bin = convert_to_binary(numbers[i]);
    long long bin_sz = bin.size();
    long long min_bin = 1;
    while (1) {
      min_bin -= 1;
      if (min_bin >= bin_sz) {
        long long to_append = min_bin - bin_sz;
        string tmp_str = "";
        for (long long i = 0; i < to_append; i++) {
          bin.insert(0, "0");
        }
        break;
      }
      min_bin += 1;
      min_bin *= 2;
    }
    answer.push_back(check_odd(bin));
  }
  return answer;
}