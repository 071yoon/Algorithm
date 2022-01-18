#include <iostream>
#include <algorithm>
using namespace std;

int main(){

	int arr[1001];
	int cnt, num;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> arr[i];
	}
	sort(arr, arr + cnt);
	for(int i = 0; i < cnt; i++)
		cout << arr[i] << "\n";
}