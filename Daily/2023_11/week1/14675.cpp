#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int cnt;
    vector <int> vec[100001];

    cin >> cnt;
    for(int i = 0; i < cnt - 1; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        vec[tmp1].push_back(tmp2);
        vec[tmp2].push_back(tmp1);
    }

    int ans_cnt;
    cin >> ans_cnt;
    for(int i = 0; i < ans_cnt; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        if (tmp1 == 1) {
            if (vec[tmp2].size() > 1) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        } else {
            cout << "yes\n";
        }
    }
}