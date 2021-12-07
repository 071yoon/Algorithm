#include <stdio.h>
#include <algorithm>
#include <vector>

std::vector<std::pair<int, int> > v;

int main(){
	int cnt, tmpx, tmpy;

	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++){
		scanf("%d %d", &tmpx, &tmpy);
		v.push_back(std::pair<int, int>(tmpy, tmpx));
	}
	std::sort(v.begin(), v.end());
	for (int i = 0; i < cnt; i++){
		printf("%d %d\n", v[i].second, v[i].first);
	}
}