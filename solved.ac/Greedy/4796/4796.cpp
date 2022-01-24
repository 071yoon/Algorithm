#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int L, P, V;
	int cnt = 1;
	cin >> L >> P >> V;
	while(L&&P&&V){
		int ret = 0;
		int ret2 = 0;
		ret = V / P;
		ret *= L;
		ret2 = V % P;
		if (ret2 >= L)
			ret2 = L;
		cout << "Case " << cnt << ": " << ret + ret2 << "\n";
		cnt++;
		cin >> L >> P >> V;
	}
}