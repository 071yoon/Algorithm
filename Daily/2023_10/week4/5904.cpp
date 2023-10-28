#include <iostream>
using namespace std;

char get_moo(int total_moo, int cur, int N) {
    int prev = (total_moo - cur - 3) / 2;

    if (N <= prev) {
        return get_moo(prev, cur - 1, N);
    } else if (N > prev + cur + 3) {
        return get_moo(prev, cur - 1, N - prev - cur - 3);
    } else {
        if (N - prev - 1 == 0) {
            return 'm';
        }
        return 'o';
    }
}

int main(){
    int N;
    cin >> N;

    int total_moo = 3;
    int cur = 0;
    while(N > total_moo) {
        cur += 1;
        total_moo = total_moo * 2 + cur + 3;
    }
    cout << get_moo(total_moo, cur, N);
    return 0;
}