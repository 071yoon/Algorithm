#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while(T--){
		int base, num, tmp;
		vector <int> ban[4];
		cin >> base >> num;
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < num; j++){
				cin >> tmp;
				ban[i].push_back(tmp);
			}
		}
		vector <int> sum[2];
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < num; j++){
				for(int k = 0; k < num; k++){
					sum[i].push_back(ban[i * 2][j] + ban[i * 2 + 1][k]);
				}
			}
			sort(sum[i].begin(), sum[i].end());
			sum[i].erase(unique(sum[i].begin(), sum[i].end()), sum[i].end());
		}
		int target = 987654321; int real = 987654321;
		int flag = 0;
		for(int i = 0; i < num * num; i++){
			int gijun = sum[0][i];
			int lo = 0, hi = num * num - 1;
			while(lo <= hi){
				int mid = (lo + hi) / 2;
				int cmp = gijun + sum[1][mid];
				if (target > abs(base - cmp)){
					target = abs(base - cmp);
					real = cmp;
				}
				else if (target == abs(base - cmp)){
					if (cmp < real) real = cmp;
				}
				if (base < gijun + sum[1][mid]){
					hi = mid - 1;
				}
				else if (base > gijun + sum[1][mid]){
					lo = mid + 1;
				}
				else{
					flag = 1;
					break ;
				}
			}
			if (flag){
				cout << base << "\n";
				break;
			}
		}
		if (!flag){
			cout << real << "\n";
		}
	}	
}