#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while(1) {
        int N, M;
        cin >> N >> M;
        if (N == 0 && M == 0) return 0;
        vector <int> sang;

        int ans = 0;
        for(int i = 0; i < N; i++) {
            int tmp;
            cin >> tmp;
            sang.push_back(tmp);
        }
        for(int i = 0; i < M; i++) {
            int tmp;
            cin >> tmp;
            int start = 0;
            int end = N - 1;
            while(start <= end) {
                int mid = (start + end) / 2;
                if (sang[mid] == tmp) {
                    ans += 1;
                    break;
                } else if (sang[mid] > tmp) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }
        cout << ans << "\n";
    }
}