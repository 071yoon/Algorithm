#include <iostream>
#include <algorithm>
using namespace std;

int combi(int n, int r){
	if (n == r || r == 0)
		return (1);
	else
		return (combi(n - 1, r - 1) + combi(n - 1, r));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		
	}
	cout << combi(N,M) << "\n";
}