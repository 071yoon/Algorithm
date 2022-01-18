#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
int main(){
	int cnt, value, num, ret;
	vector <int> v;

	scanf("%d %d", &cnt, &value);
	for(int i = 0; i < cnt; i++){
		scanf("%d", &num);
		v.push_back(num);
	}
	int loop = v.size() - 1;
	ret = 0;
	int tmp;
	while (value != 0){
		if (value / v[loop] >= 1){
			tmp = value / v[loop];
			value -= v[loop] * tmp;
			ret += tmp;
		}
		else
			loop--;
	}
	printf("%d", ret);

}