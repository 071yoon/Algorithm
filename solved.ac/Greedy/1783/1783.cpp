#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	if (N == 1){
		cout << "1\n";
	}
	else if (N == 2){
		cout << min(4, (M + 1) / 2) << "\n";
	}
	else{
		if (M < 7){
			cout << min(4, M) << "\n";
		}
		else{
			cout << M - 2 << "\n";
		}
	}
}