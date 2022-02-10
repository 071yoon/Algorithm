#include <iostream>
#include <string>
#include <unordered_map>
#include <cstring>
using namespace std;

int roots[100001];
int sz[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int total;
	cin >> total;
	while(total--){
		int cnt;

		for(int i = 0; i < cnt; i++){
			roots[i] = i;
			sz[i] = 1;
		}
		unordered_map <string, int> ump;
		for(int i = 0; i < cnt; i++){
			string tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			ump[tmp1]++;
		}
	}
}