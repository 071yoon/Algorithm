#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int visited[10];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int n, d;
    cin >> n >> d;
    vector<int> v(d);
	for(int i = 0; i < d; i++)
		v[i] = i;
    while (next_permutation(v.begin(), v.end())){
        if (v[0] == 0) {
            continue;
        }
        int sum = 0;
        for (int i = d - 1; i >= 0; --i) {
            int temp = 1;
            for (int j = 1; j <= d - i - 1; ++j) {
                temp *= d;
            }
            sum += temp * v[i];
        }
        if (sum > n) {
            cout << sum;
            return 0;
        }
    }
	
    cout << -1;
    return 0;
}