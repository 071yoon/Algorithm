#include <iostream>

using namespace std;

int cmpt, links, num1, num2, virus;
int arr[101][101] = {0};

void DFS(int num){
	for(int i = 1; i <= cmpt; i++){
		if(arr[i][num])
			arr[i][num] = 0;
	}
	for(int i = 1; i <= cmpt; i++){
		if(arr[num][i]){
			DFS(i);
			virus++;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> cmpt;
	cin >> links;
	for(int i = 0; i < links ; i++){
		cin >> num1 >> num2;
		arr[num1][num2] = 1;
		arr[num2][num1] = 1;
	}
	virus = 0;
	DFS(1);
	cout << virus;
}