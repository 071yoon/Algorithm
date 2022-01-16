#include <iostream>
using namespace std;

int gcd(int M, int N){
	int tmp;
	int org_M = M, org_N = N;
	while (N){
		tmp = M % N;
		M = N;
		N = tmp;
	}
	return ((org_M * org_N) / M);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt, M, N, x, y, lim;
	cin >> cnt;
	while(cnt--){
		int ret = 1;
		cin >> M >> N >> x >> y;
		lim = gcd(M, N);
		ret = x;
		int before = x % N;
		while (ret <= lim){
			if (before == 0)//point ::case 8 2 4 2::
				before = N;
			if (before == y)
				break ;
			ret += M;
			before = (before + M) % N;
		}
		if (ret > lim)
			cout << "-1\n";
		else
			cout << ret << "\n";
	}
}