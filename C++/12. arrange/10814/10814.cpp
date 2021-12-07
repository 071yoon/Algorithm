#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>

bool compare(std::pair<int, std::string> a, std::pair<int, std::string> b){
	return a.first < b.first;	
}
std::vector<std::pair<int, std::string> > v;

int main(){
	int cnt, num;
	char *str = new char[50];

	std::ios::sync_with_stdio(false);
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++){
		scanf("%d %s", &num, str);
		v.push_back(std::pair<int, std::string>(num, str));
	}
	stable_sort(v.begin(), v.end(), compare);//stable 사용시 동일 한 값에 비교시에 유지
	for(int i = 0; i < cnt; i++)
        std::cout << v[i].first << ' ' << v[i].second << '\n';
}