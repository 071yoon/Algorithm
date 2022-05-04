#include <iostream>
#include <cmath>
using namespace std;

int x_1, y_1, x2, y2, cnt, nx, ny, ret, r;

void solve(){
	int flag = 0;
	if (pow(x_1 - nx, 2) + pow(y_1 - ny, 2) < pow(r, 2)) flag++;
	if (pow(x2 - nx, 2) + pow(y2 - ny , 2) < pow(r, 2)) flag++;
	if (flag % 2) ret++;
}

void inputs(){
	cin >> x_1 >> y_1 >> x2 >> y2 >> cnt;
	ret = 0;
	while(cnt--){
		cin >> nx >> ny >> r;
		solve();
	}
	cout << ret << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while(T--){
		inputs();
	}
}