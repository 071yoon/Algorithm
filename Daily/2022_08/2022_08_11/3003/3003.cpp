//1 1 2 2 2 8
#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int num;
	int counts[6] = {1, 1, 2, 2, 2, 8};
	for(int i = 0; i < 6; i++){
		cin >> num;
		cout << counts[i] - num << " ";
	}
}