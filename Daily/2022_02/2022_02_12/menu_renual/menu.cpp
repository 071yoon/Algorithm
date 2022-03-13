#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
unordered_map <string, int> convert;

void conversion(string str, string ret, int index){
    if (ret.size() > 1){
        convert[ret]++;
    }
    for(int i = index + 1; i < str.size(); i++){
        conversion(str, ret + str[i], i);    
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int i = 0; i < orders.size(); i++){
        sort(orders[i].begin(), orders[i].end());
        for(int j = 0; j < orders[i].size(); j++){
            string tmp = "";
            tmp += orders[i][j];
            conversion(orders[i], tmp, j);
        }
    }
    
    for(int i = 0; i < course.size(); i++){
        int sz = course[i];
        vector <pair<int, string> > tmp_vec;
        int max_val = 0;
        for(auto it = convert.begin(); it != convert.end(); it++){
            if ((it->first).size() == sz && (it->second) >= 2){
                tmp_vec.push_back(make_pair(it->second, it->first));
                max_val = max(max_val, it->second);
            }
        }
        for(int i = 0; i < tmp_vec.size(); i++){
            if (tmp_vec[i].first == max_val){
                answer.push_back(tmp_vec[i].second);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
