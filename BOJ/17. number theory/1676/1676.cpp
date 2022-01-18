#include <iostream>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt;
	cin >> cnt;
	int ret = 0;
	for (int i = 1; i <= cnt; i++){
		int tmp = i;
		while (tmp % 5 == 0){
			ret++;
			tmp /= 5;
		}
	}
	cout << ret;
}