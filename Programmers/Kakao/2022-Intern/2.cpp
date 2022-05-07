/*
100 / 100
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
long long summer[601000] = {0};

int solution(vector<int> queue1, vector<int> queue2) {
    int sz = queue1.size();
    int answer = 2e9;
    summer[0] = queue1[0];
    for(int i = 1; i < sz; i++){
        summer[i] = summer[i - 1] + queue1[i];
    }
    for(int i = 0; i < sz; i++){
        summer[i + sz] = summer[i + sz - 1] + queue2[i];
    }
    long long target = summer[sz * 2 - 1] / 2;
    int starter = 0;
    for(int i = 2 * sz - 1; i >= 0; i--){
        if (summer[i] < target) break;
        while(summer[i] - summer[starter] > target){
            starter++;
        }
        while(summer[i] - summer[starter] < target){
            starter--;
        }
        if (summer[i] - summer[starter] == target){
            if (i <= sz - 2){
                answer = min(answer, i + 2 + starter + sz);
            }
            else{
                answer = min(answer, i + 2 + starter - sz);
            }
        }
    }
    if (answer == 2e9) return -1;
    else return answer;
}