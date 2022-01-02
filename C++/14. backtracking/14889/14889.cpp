#include <iostream>
#include <math.h>

using namespace std;
int cnt;
int indexer;
int arr[20][20];
int indexy[20] = {0};
int mini = 2147483647;

int calcul(int i, int j){
	return (arr[i][j]);
}

int finder(int look){
	if (indexer == cnt / 2){
		int tmp1 = 0;
		int tmp2 = 0;
		for(int i = 0; i < cnt; i++){
			for(int j = 0; j < cnt; j++){
				if(indexy[i] && indexy[j])
					tmp1 += calcul(i, j);
			}
		}
		for(int i = 0; i < cnt; i++){
			for(int j = 0; j < cnt; j++){
				if(!indexy[i] && !indexy[j])
					tmp2 += calcul(i, j);
			}
		}
		if (mini > abs(tmp2 - tmp1))
			mini = abs(tmp2 - tmp1);
		return (0);
	}
	for(int i = look; i < cnt; i++){
		if (indexy[i] == 0){
			indexy[i] = 1;
			indexer++;
			finder(i + 1);
			indexy[i] = 0;
			indexer--;
		}
	}
	return (0);
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> cnt;
	indexer = 0;
	for(int i = 0; i < cnt; i++){
		for(int j = 0; j < cnt; j++)
			cin >> arr[i][j];
	}
	finder(0);
	cout << mini;

}
