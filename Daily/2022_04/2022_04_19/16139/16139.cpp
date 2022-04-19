#include <iostream>
#include <cstring>
using namespace std;

string str;
int tmp[200001][26];

void solve(){
	char num;
	int l, r;
	cin >> num;
	cin >> l >> r;
	int p1 = l > 0 ? tmp[l - 1][num - 'a'] : 0;
	int p2 = tmp[r][num - 'a'];
	cout << p2 - p1 << '\n';
}

void inputs(){
	int cnt;
	cin >> str;
	for(int i = 0; i < str.size(); i++){
		if (i != 0){
			for(int k = 0; k < 26; k++){
				tmp[i][k] = tmp[i - 1][k];
			}
		}
		tmp[i][str[i] - 'a']++;
	}
	cin >> cnt;
	while(cnt--){
		solve();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
}