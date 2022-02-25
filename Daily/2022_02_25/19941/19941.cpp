#include <string>
#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, K, ret = 0;
	cin >> N >> K;
	string hp;
	cin >> hp;
	for(int i = 0; i < N; i++){
		if (hp[i] == 'P'){
			for(int j = K * -1; j <= K; j++){
				if (i + j >= 0 && i + j < N){
					if (hp[i + j] == 'H'){
						hp[i + j] = '0';
						ret++;
						break ;
					}
				}
			}
		}
	}
	cout << ret << "\n";
}
// 6mins 0sec