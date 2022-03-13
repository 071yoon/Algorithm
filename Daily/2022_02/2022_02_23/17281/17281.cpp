#include <algorithm>
#include <iostream>
using namespace std;

int order[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
int inning[51][9] = {0};
int ret = 0;

int main(){
	int cnt; 
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		for(int j = 0; j < 9; j++){
			cin >> inning[i][j];
		}
	}
	do{
		if (order[3] != 0){
			continue ;
		}
		int taja = 0;
		int tmp = 0;
		for(int i = 0; i < cnt; i++){
			int outs = 0;
			int homes[3] = {0};
			while(outs < 3){
				int pl = order[taja];
				if (inning[i][pl] == 1){
					if (homes[2]){
						homes[2] = 0;
						tmp++;
					}
					if (homes[1]){
						homes[1] = 0;
						homes[2]++;
					}
					if (homes[0]){
						homes[0] = 0;
						homes[1]++;
					}
					homes[0]++;
				}
				else if (inning[i][pl] == 0){
					outs += 1;
				}
				else if (inning[i][pl] == 2){
					if (homes[2]){
						homes[2] = 0;
						tmp++;
					}
					if (homes[1]){
						homes[1] = 0;
						tmp++;
					}
					if (homes[0]){
						homes[0] = 0;
						homes[2]++;
					}
					homes[1]++;
				}
				else if (inning[i][pl] == 3){
					if (homes[2]){
						homes[2] = 0;
						tmp++;
					}
					if (homes[1]){
						homes[1] = 0;
						tmp++;
					}
					if (homes[0]){
						homes[0] = 0;
						tmp++;
					}
					homes[2]++;
				}
				else if (inning[i][pl] == 4){
					if (homes[2]) tmp++;
					if (homes[1]) tmp++;
					if (homes[0]) tmp++;
					tmp++;
					homes[0] = 0; homes[1] = 0; homes[2] = 0;
				}
				taja = (taja + 1) % 9;
			}
		}
		ret = max(ret, tmp);
	}while(next_permutation(order, order + 9));
	cout << ret << "\n";
}