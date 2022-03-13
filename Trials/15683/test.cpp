#include <iostream>
using namespace std;

void change(int arr1[8][8], int arr2[8][8]){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			arr1[i][j] = arr2[i][j];
		}
	}
}

int main(){
	int arr1[8][8] = {0};
	int arr2[8][8] = {{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1}};
	change(arr1, arr2);
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			cout << arr1[i][j] << " ";
		}
		cout << "\n";
	}
}