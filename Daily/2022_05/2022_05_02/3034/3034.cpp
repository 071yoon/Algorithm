#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, W, H, tmp;
	cin >> N >> W >> H;
	while(N--){
		cin >> tmp;
		if (tmp * tmp > W * W + H * H){
			cout << "NE\n";
		}
		else{
			cout << "DA\n";
		}
	}
}