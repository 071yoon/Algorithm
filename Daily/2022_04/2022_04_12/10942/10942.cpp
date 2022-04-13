#include <iostream>
using namespace std;

int arr[2001];
bool pali[2001][2001] = {0};
int cnt;

void inputs(){
	cin >> cnt;

	int tmp;
	for(int i = 0; i < cnt; i++){
		cin >> arr[i];
	}

	for(int i = 0; i < cnt; i++){ //size 1
		pali[i][i] = 1;
	}

	for(int i = 0; i < cnt - 1; i++){ //size 2
		if (arr[i] == arr[i + 1])
			pali[i][i + 1] = 1;
	}

	for(int i = 1; i < cnt - 1; i++){ //size 3
		for(int j = 0; j < cnt - i; j++){
			if (arr[j] == arr[i + j] && pali[j + 1][i + j - 1])
				pali[j][i + j] = 1;
		}
	}
}

void solve(){
	int tc, num1, num2;
	cin >> tc;
	while(tc--){
		cin >> num1 >> num2;
		cout << pali[num1 - 1][num2 - 1] << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
	solve();
}