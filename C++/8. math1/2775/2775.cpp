#include <stdio.h>


int main(){
	int **apart;
	int floor, room, cnt;
	
	scanf("%d", &cnt);
		for (int k = 0; k < cnt; k++){
		scanf("%d %d", &floor, &room);
		floor += 1;
		apart = new int*[floor];
		for (int i = 0; i < floor; i ++){
			apart[i] = new int[room];
			apart[i][0] = 1;
		}
		for (int i = 0; i < room; i++)
			apart[0][i] = i + 1;
		for (int i = 1; i < floor; i++){
			for(int j = 1; j < room; j++){
				apart[i][j] = apart[i-1][j] + apart[i][j-1];
			}
		}
		printf("%d\n", apart[floor-1][room-1]);
	}
}