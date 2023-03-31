#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    int today_year = stoi(today.substr(0, 4));
    int today_month = stoi(today.substr(5, 2));
    int today_day = stoi(today.substr(8, 2));
    map<char, int> terms_map;
    for(int i = 0; i < terms.size(); i++) {
        char key = terms[i][0];
        int monthly = stoi(terms[i].substr(2));
        terms_map.insert(pair<char, int>(key, monthly));
    }
    vector<int> answer;   
    for(int i = 0; i < privacies.size(); i++) {
        int privacy_year = stoi(privacies[i].substr(0, 4));
        int privacy_month = stoi(privacies[i].substr(5, 2));
        int privacy_day = stoi(privacies[i].substr(8, 2));
        char key = privacies[i][11];

        privacy_month += terms_map[key];
        int how_many_times_will_divide = privacy_month / 12;
        if (privacy_month % 12 == 0) {
            how_many_times_will_divide -= 1;
        }
        privacy_year += how_many_times_will_divide;
        privacy_month -= (how_many_times_will_divide * 12);

        if (privacy_day == 1) {
            if (privacy_month == 1) {
                privacy_year -= 1;
                privacy_month = 12;
                privacy_day = 28;
            } else {
                privacy_month -= 1;
                privacy_day = 28;
            }
        } else {
            privacy_day -= 1;
        }

        // privacy day가 today 보다 더 적으면 파기
        if (today_year >= privacy_year) {
            if (today_year > privacy_year){
                answer.push_back(i + 1);
                continue;
            } 
            if (today_month >= privacy_month) {
                if (today_month > privacy_month){
                    answer.push_back(i + 1);
                    continue;
                } 
                if (today_day > privacy_day) {
                    answer.push_back(i + 1);
                }
            }
        }
    }
    return answer;
}