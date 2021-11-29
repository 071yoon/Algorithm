#include <stdio.h>
#include <algorithm>

int main(){
	int x, y;
	char BW[8][8] = {0};
	char BW2[8][8] = {0};

	scanf("%d %d", &y, &x);
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if ((i + j) % 2 == 0)
				BW[i][j] = 'B';
			else
				BW[i][j] = 'W';
		}
	}
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if ((i + j) % 2 == 0)
				BW2[i][j] = 'W';
			else
				BW2[i][j] = 'B';
		}
	}
	char str_cmp[50][50] = {0};
	for (int j = 0; j < y; j++){
		scanf("%s", str_cmp[j]);
	}
	int *num_cnt1;
	int *num_cnt2;
	num_cnt1 = new int[(y - 7) * (x - 7)];
	num_cnt2 = new int[(y - 7) * (x - 7)];
	for (int i = 0; i < (y - 7) * (x - 7); i++){
		num_cnt1[i] = 0;
		num_cnt2[i] = 0;
	}
	int cnt = 0;
	for (int i = 0; i < y - 7; i++){
		for (int j = 0; j < x - 7; j++){
			for (int k = 0; k < 8; k++){
				for (int n = 0; n < 8; n++){
					if (BW[k][n] != str_cmp[i+k][j+n]){
						num_cnt1[cnt]++;
					}
					if (BW2[k][n] != str_cmp[i+k][j+n])
						num_cnt2[cnt]++;
				}
			}
			cnt++;
		}
	}
	int min1, min2;
	min1 = *std::min_element(num_cnt1, num_cnt1 + (y - 7) * (x - 7));
	min2 = *std::min_element(num_cnt2, num_cnt2 + (y - 7) * (x - 7));
	if (min1 >= min2)
		printf("%d", min2);
	else
		printf("%d", min1);
}