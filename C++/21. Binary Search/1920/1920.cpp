#include <iostream>
#include <algorithm>

using namespace std;
int arr[100001];

void finder(int start, int end, int num){
	int mid = start + (end - start) / 2;
	if (arr[mid] == num){
		cout << "1\n";
	}
	else if (start == end){
		cout << "0\n";
	}
	else if (mid == start){
		if (arr[start + 1] == num){
			cout << "1\n";
		}
		else
			cout << "0\n";
	}
	else if (arr[mid] > num){
		finder(start, mid - 1, num);
	}
	else if (arr[mid] < num){
		finder(mid + 1, end, num);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	sort(arr, arr + N);
	cin >> M;
	int num;
	for(int i = 0; i < M; i++){
		cin >> num;
		finder(0, N - 1, num);
	}
}