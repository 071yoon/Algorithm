#include <iostream>
#include <vector>
using namespace std;
int test_case, N, M;
vector <int> vec;

int DP[10001] = {0};

int Solve(){
	for(int i = 0; i < N; i++){
		for(int j = vec[i]; j <= M; j++){
			cout << j - vec[i] << "\n";
			DP[j] += DP[j - vec[i]];
		}
	}
	return DP[M];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> test_case;
	while(test_case--){
		cin >> N;

		vec.clear();
		memset(DP, 0, sizeof(DP)); DP[0] = 1;
		for (int i = 0; i < N; i++) {
			int num = 0; cin >> num;
			vec.push_back(num);
		}
		cin >> M;
		cout << Solve() << "\n";
	}
}

/*

1 3 5
9 (1 1 1 1 1 1 1 1 1) (1 1 1 1 1 1 3) (1 1 1 3 3) (1 3 5) (1 1 1 1 5) 
5 (1 1 1 1 1) (1 1 3) (5)

*/