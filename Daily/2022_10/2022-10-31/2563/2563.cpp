#include <iostream>
using namespace std;

int main(){
	int white[100][100] = {0};
	int cnt;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		int x, y;
		cin >> x >> y;
		for(int i = x; i < x + 10; i++){
			for(int j = y; j < y + 10; j++){
				white[i][j] = 1;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			if(white[i][j] == 1){
				ans++;
			}
		}
	}
	cout << ans << "\n";
}