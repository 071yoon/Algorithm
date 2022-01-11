#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	bool arr[21];
	int cnt, num;
	string phrase;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> phrase;
		if (phrase == "add"){
			cin >> num;
			if (!arr[num]){
				arr[num] = 1;
			}
		}
		else if (phrase == "remove"){
			cin >> num;
			if (arr[num])
				arr[num] = 0;
		}
		else if (phrase == "check"){
			cin >> num;
			if (arr[num])
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (phrase == "toggle"){
			cin >> num;
			if (arr[num])
				arr[num] = 0;
			else
				arr[num] = 1;
		}
		else if (phrase == "all"){
			memset(arr, 1, sizeof(arr));
		}
		else if (phrase == "empty"){
			memset(arr, 0, sizeof(arr));
		}
	}
}