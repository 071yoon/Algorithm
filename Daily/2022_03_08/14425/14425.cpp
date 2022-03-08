#include <cstring>
#include <set>
#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	set <string> s;
	string str;

	for(int i = 0; i < N; i++){
		cin >> str;
		s.insert(str);
	}
	int ret = 0;
	for(int i = 0; i < M; i++){
		cin >> str;
		if(s.find(str) != s.end()){
			ret++;
		}
	}
	cout << ret << "\n";
}