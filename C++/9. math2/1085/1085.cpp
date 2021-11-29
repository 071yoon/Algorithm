#include <stdio.h>
#include <algorithm>

int main(){
	int x, y, w, h;

	scanf("%d %d %d %d", &x, &y, &w, &h);
	int num[4];

	num[0] = x;
	num[1] = y;
	num[2] = w - x;
	num[3] = h - y;
	printf("%d", *std::min_element(num, num + 4));
}