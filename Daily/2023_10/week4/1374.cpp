#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int cnt;
    vector <pair<int, int> > courses;
    
    cin >> cnt;
    for(int i = 0; i < cnt; i++) {
        // 번호, 시작 시간, 종료 시간
        int num, start, end;
        cin >> num >> start >> end;
        courses.push_back(make_pair(start, 1));
        courses.push_back(make_pair(end, -1));
    }
    sort(courses.begin(), courses.end());

    int cur = 0;
    int ans = 0;
    for(int i = 0; i < courses.size(); i++) {
        cur += courses[i].second;
        ans = max(cur, ans);
    }  
    cout << ans << "\n";
}