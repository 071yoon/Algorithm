#include <stdio.h>
#include <math.h>

int main(){
	int cnt;
	int x1, y1, r1, x2, y2, r2;
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++){
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		long long cord_dif = pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2);
		long long check_r = pow(r1 + r2, 2);
		long long check_r2 = pow(r1 - r2, 2);
		if (cord_dif == 0 && r1 == r2)
			printf("-1\n");
		else if (cord_dif == 0)
			printf("0\n");
		else if (check_r == cord_dif || check_r2 == cord_dif)
			printf("1\n");
		else if (check_r > cord_dif && check_r2 < cord_dif)
			printf("2\n");
		else
			printf("0\n");
	}
}