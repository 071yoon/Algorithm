#include <iostream>
using namespace std;

int total[101][24] = {0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int pcs, people, hours, pc, hour;
	cin >> pcs >> people >> hours;
	for(int i = 1; i <= pcs; i++){
		total[i][0] = 1;
	}
	for(int i = 0; i < people; i++){
		cin >> pc >> hour;
		if (hour > hours){
			continue ;
		}
		else {
			for(int i = hours; i >= 0; i--){
				if (total[pc][i] && i + hour <= hours){
					total[pc][i + hour] = 1;
				}
			}
			total[pc][hour] = 1;
		}
	}
	for(int i = 1; i <= pcs; i++){
		for(int j = hours; j >= 0; j--){
			if (total[i][j]){
				cout << i << " " << j << "\n";
				break ;
			}
		}
	}
}