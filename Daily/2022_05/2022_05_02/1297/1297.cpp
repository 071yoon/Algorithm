#include <iostream>
#include <cmath>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int D, W, H;
	cin >> D >> H >> W;
	double tmp = sqrt(H * H + W * W);
	cout << int(H * D / tmp) << " " << int(W * D / tmp) << "\n";

}