#include <vector>
#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int answer = 0;
	int hole, cnt;
	int dig[200];
	cin >> hole >> cnt;
	vector <int> cache; //plug, priority

	for(int i = 0; i < cnt; i++){
		cin >> dig[i];
	}
	for(int i = 0; i < cnt; i++){
		int flag = 0;
		/*
		cout << i << " : ";
		for(int k = 0; k < cache.size(); k++){
			cout << cache[k] << " ";
		}
		cout << "\n";
		*/
		for(int j = 0; j < cache.size(); j++){
			if (dig[i] == cache[j]){
				flag = 1;
				break ;
			}
		}
		if (flag) continue ;
		if (cache.size() < hole){
			cache.push_back(dig[i]);
			continue ;
		}
		vector <int> tmp(cache.begin(), cache.end());
		int index = i + 1;
		while (tmp.size() > 1 && index < cnt){
			for(int k = 0; k < tmp.size(); k++){
				if (dig[index] == tmp[k]){
					tmp.erase(tmp.begin() + k);
					break ;
				}
			}
			index++;
		}
		for(int j = 0; j < cache.size(); j++){
			if (cache[j] == tmp[0]){
				cache.erase(cache.begin() + j);
				cache.push_back(dig[i]);
				answer += 1;
				break ;
			}
		}
	}
	cout << answer << "\n";
}
/*
1. 우선 채우기
2. 있으면 그냥 다음거
3. 없으면 캐시를 복사 후 하나 남을때 까지 빼면서 진행 (하나 남으면 걔를 빼고, 아니면 끝 도착이면 암거나)

3 14
1 4 3 2 5 4 3 2 5 3 4 2 3 4
1 2 3 4 5 6 7 8 9 1011121314
3 [1 4 3]
4 [2 4 3] +1
5 [5 4 3] +1
8 [2 5 3] +1
9 [2 4 3] +1


*/