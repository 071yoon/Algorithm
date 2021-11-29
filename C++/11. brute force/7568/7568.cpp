#include <stdio.h>
#include <algorithm>

int main(){
	int arr[50][2] = {0};
	int *rank;
	int cnt, x, y;

	scanf("%d", &cnt);
	rank = new int[cnt];
	for (int i = 0; i < cnt; i++){
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	for (int i = 0; i < cnt; i++){
		int ranky = 1;
		for (int j = 0; j < cnt; j++){
			if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1]){
				ranky++;
			}
		}
		rank[i] = ranky;
	}
	for (int i = 0; i < cnt; i++)
		printf("%d ", rank[i]);
}