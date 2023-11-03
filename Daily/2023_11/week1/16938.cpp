#include <iostream>
#include <vector>
using namespace std;

int pc, maxs, mins, diff;
vector <int> problems;
int ans = 0;

void back_track(int cnt, int max_num, int min_num, int sum) {
    if (cnt == pc) {
        if (max_num - min_num >= diff && sum >= maxs && sum <= mins) {
            ans++;
        }
        return ;
    }
    back_track(cnt + 1, max(max_num, problems[cnt]), min(min_num, problems[cnt]), sum + problems[cnt]);
    back_track(cnt + 1, max_num, min_num, sum);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    cin >> pc >> maxs >> mins >> diff;
    for(int i = 0; i < pc; i++) {
        int num;
        cin >> num;
        problems.push_back(num);
    }

    back_track(0, -987654321, 987654321, 0);
    cout << ans << "\n";

}