#include <string>
#include <vector>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> student, vector<int> point) {
    int answer = 0;
    vector <pair<int, int> > good;
    vector <pair<int, int> > bad;
    for(int i = 1; i <= n / 2; i++) {
        good.push_back(make_pair(i, 0));
    }
    for(int i = n / 2 + 1; i <= n; i++){
        bad.push_back(make_pair(i, 0));
    }
    for(int i = 0; i < student.size(); i++) {
        bool flag = false;
        pair<int, int> mini = good[0];
        int min_index = 0;
        for(int j = 0; j < good.size(); j++) {
            if(good[j].first == student[i]) {
                good[j].second += point[i];
                flag = true;
            }
            if (good[j].second <= mini.second && good[j].first >= mini.first) {
                mini = good[j];
                min_index = j;
            }
        }
        if (flag) continue ;
        pair<int, int> maxi = bad[0];
        int max_index = 0;
        for(int j = 0; j < bad.size(); j++) {
            if(bad[j].first == student[i]) {
                bad[j].second += point[i];
            }
            if (bad[j].second >= maxi.second && bad[j].first <= maxi.first) {
              cout << "maxi.second : " << maxi.second << endl;
                maxi = bad[j];
                max_index = j;
            }
        }
        cout << "min key " << mini.first << " val " << mini.second << " max key " << maxi.first << " val " << maxi.second << endl;
        if (mini.second <= maxi.second && mini.first > maxi.first) {
            answer++;
            good[min_index] = maxi;
            bad[max_index] = mini;
        }
    }
    return answer;
}