#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, r = 0;
	cin >> n;
	for(int i = 1; i <= n; i *= 10){
		r = r + n - i + 1;
	}
	cout << r << "\n";
}