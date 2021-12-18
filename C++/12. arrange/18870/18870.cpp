#include <stdio.h>
#include <algorithm>
#include <vector>

int main(){
	std::vector <int> v, org;
	int cnt, num;

	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++){
		scanf("%d", &num);
		v.push_back(num);
		org.push_back(num);
	}
	std::sort(v.begin(), v.end());
	v.erase((std::unique(v.begin(), v.end())), v.end());
	for(int i = 0; i < cnt; i++){
		printf("%ld ", lower_bound(v.begin(), v.end(), org[i]) - v.begin());
	}
}