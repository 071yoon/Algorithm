#include <iostream>
#include <algorithm>
using namespace std;

int mapp[1024] = {0};

int solution(int starter, int ender){
	int mid = (starter + ender) / 2;
	if (starter + 1 == ender){
		return (max(mapp[starter], mapp[ender]));
	}
	int lefter = *max_element(mapp + starter, mapp + mid) + solution(mid + 1, ender);
	int righter = solution(starter, mid) + *max_element(mapp + mid + 1, mapp + ender);
	return (max(lefter, righter));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> mapp[i];
	}
	cout << solution(0, cnt - 1) << "\n";
}
//42mins 30