#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int r1, s;
	// (r1 + r2) / 2 = s;
	// r2 = 2 * s - r1
	cin >> r1 >> s;
	cout <<  ( 2 * s - r1 ) << "\n";
}