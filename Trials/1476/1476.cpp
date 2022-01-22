#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int E, S, M;
	int test_E = 1, test_S = 1, test_M = 1;
	cin >> E >> S >> M;
	int day = 1;
	while(1){
		if (test_E == E && test_S == S && test_M == M)
			break ;
		day++;
		test_E = day % 15;
		if (test_E == 0)
			test_E = 15;
		test_S = day % 28;
		if (test_S == 0)
			test_S = 28;
		test_M = day % 19;
		if (test_M == 0)
			test_M = 19;
	}
	cout << day << "\n";
}