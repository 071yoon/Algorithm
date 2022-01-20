#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int ret[3], time;
	cin >> time;
	ret[0] = time / 300;
	time %= 300;
	ret[1] = time / 60;
	time %= 60;
	ret[2] = time / 10;
	time %= 10;
	if (time != 0)
		cout << "-1\n";
	else
		cout << ret[0] << " " << ret[1] << " " << ret[2] << "\n";
}