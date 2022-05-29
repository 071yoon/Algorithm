#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int cnt;
	cin >> cnt;
	for(int i = 0; i < cnt - 1; i++){
		for(int j = 0; j < i + 1; j++){
			cout << "*";
		}
		cout << "\n";
	}
	for(int i = 0; i < cnt; i++){
		cout << "*";
	}
	cout << "\n";
	for(int i = cnt - 1; i > 0; i--){
		for(int j = i; j > 0; j--){
			cout << "*";
		}
		cout << "\n";
	}
}