#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

bool compare(int i, int j){
	return j < i;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int cnt;
	int alphabet[26] = {0};
	string str;
	cin >> cnt;
	while(cnt--){
		cin >> str;
		for(int i = 0; i < str.size(); i++){
			alphabet[str[i] - 'A'] += pow(10, str.size() - i - 1);
		}
	}
	sort(alphabet, alphabet + 26, compare);
	long long ret = 0;
	int i = 0;
	int num = 9;
	while(alphabet[i]){
		ret += alphabet[i] * num;
		num--;
		i++;
	}
	cout << ret << "\n";
}