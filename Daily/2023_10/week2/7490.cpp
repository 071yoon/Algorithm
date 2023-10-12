#include <iostream>
#include <string>
using namespace std;


void back_track(int sum, int sign, int cur, int next_num, int end, string str) {
    if (next_num == end) {
        if (sum + cur * sign == 0) {
            cout << str << "\n";
        }
        return;
    }
    char next_num_char = next_num + 1 + '0';
    back_track(sum, sign, cur * 10 + (next_num + 1), next_num + 1, end, str + ' ' + next_num_char);
    back_track(sum + sign * cur, 1, next_num + 1, next_num + 1, end, str + '+' + next_num_char);
    back_track(sum + sign * cur, -1, next_num + 1, next_num + 1, end, str + '-' + next_num_char);
}

int main(){
    int cnt;
    cin >> cnt;
    for(int i = 0; i < cnt; i++) {
        int num;
        cin >> num;
        back_track(0, 1, 1, 1, num, "1");
        cout << "\n";
    }
}