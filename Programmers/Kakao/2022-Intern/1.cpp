/*
100 / 100
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    int cnt[4] = {0};
    for(int i = 0; i < survey.size(); i++){
        if (survey[i] == "RT"){
            cnt[0] += choices[i] - 4;
        } else if (survey[i] == "TR") {
            cnt[0] += 4 - choices[i];
        } else if (survey[i] == "CF") {
            cnt[1] += choices[i] - 4;
        } else if (survey[i] == "FC") {
            cnt[1] += 4 - choices[i];
        } else if (survey[i] == "JM") {
            cnt[2] += choices[i] - 4;
        } else if (survey[i] == "MJ") {
            cnt[2] += 4 -  choices[i];
        } else if (survey[i] == "AN") {
            cnt[3] += choices[i] - 4;
        } else {
            cnt[3] += 4 - choices[i];
        }
    }
    string answer = "";
    if (cnt[0] > 0) answer += 'T';
    else answer += 'R';
    if (cnt[1] > 0) answer += 'F';
    else answer += 'C';
    if (cnt[2] > 0) answer += 'M';
    else answer += 'J';
    if (cnt[3] > 0) answer += 'N';
    else answer += 'A';
    return answer;
}