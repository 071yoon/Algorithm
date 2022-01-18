#include <stdio.h>
#include <vector>
#include <algorithm>

int main(){
	int num, cnt, real_num;

	std::vector <int> v;
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++){
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	printf("%d", v[0] * v[cnt - 1]);
}