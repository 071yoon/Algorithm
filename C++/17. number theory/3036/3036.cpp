#include <stdio.h>
#include <algorithm>
#include <vector>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void print_bun(int a, int b){
	int max;

	max = gcd(a, b);
	printf("%d/%d\n", a / max, b / max);
}

int main(){
	int cnt, num;
	std::vector <int> v;

	scanf("%d", &cnt);
	for(int i = 0; i < cnt; i++){
		scanf("%d", &num);
		v.push_back(num);
	}
	for(int i = 1; i < cnt; i++){
		print_bun(v[0], v[i]);
	}
}