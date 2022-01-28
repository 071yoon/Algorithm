#include <iostream>
using namespace std;

int arr[1025];

int find_max(int start, int end){
	if (start + 1 == end){
		return max(arr[start], arr[end]);
	}
	int mid = (start + end) / 2;
	int select_left = *max_element(arr + start, arr + mid + 1) + find_max(mid + 1, end);
	int select_right = *max_element(arr + mid + 1, arr + end + 1) + find_max(start, mid);
	return (max(select_left, select_right));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int num, tmp;
	cin >> num;
	for(int i = 1; i <= num; i++){
		cin >> arr[i];
	}
	cout << find_max(1, num) << "\n";
}