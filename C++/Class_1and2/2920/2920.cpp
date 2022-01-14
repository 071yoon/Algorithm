#include <iostream>
using namespace std;

int arr[8];

int asc(){
	int ascen[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	for(int i = 0; i < 8; i++){
		if(!(arr[i] == ascen[i]))
			return (0);
	}
	return (1);
}

int dsc(){
	int desc[8] = {8, 7, 6, 5, 4, 3, 2, 1};
	for(int i = 0; i < 8; i++){
		if(!(arr[i] == desc[i]))
			return (0);
	}
	return (1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for(int i = 0; i < 8; i++)
		cin >> arr[i];
	if(asc()){
		cout << "ascending\n";
		return (0);
	}
	else if (dsc()){
		cout << "descending\n";
		return (0);
	}
	cout << "mixed\n";
	return (0);
}