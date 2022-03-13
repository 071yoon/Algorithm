#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tors, me, you;
	cin >> tors >> me >> you;
	int ret = 1;
	int games = 1;
	int cnt = 1;
	while(1){
		if (games * 2 < tors){
			cnt++;
			games *= 2;
		}
		else
			break ;
	}
	me--; you--;
	int tmp = cnt;
	while(cnt--){
		me /= 2;
		you /= 2;
		if (me == you){
			cout << tmp - cnt << "\n";
			return (0);
		}
	}
	cout << "-1\n";
}
//4 -> 2, 5 -> 3, 6 -> 3, 8 -> 3, 9 -> 4
//10mins 20sec