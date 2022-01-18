#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int dp_up[1001] = {0};
	int dp_down[1001] = {0};
	int arr[1001] = {0};
	int cnt, num;
	cin >> cnt;
	for (int i = 0; i < cnt; i++){
		cin >> num;
		arr[i] = num;
	}
	int tot_max = 0;
	for (int i = 0; i < cnt; i++){
		int max = 0;
		for(int j = 0; j < i; j++){
			if (arr[i] > arr[j]){
				if (max < dp_up[j]){
					max = dp_up[j];
				}
			}
		}
		dp_up[i] = max + 1;
	}
	for (int i = cnt - 1; i >= 0; i--){
		int max = 0;
		for(int j = cnt - 1; j > i; j--){
			if (arr[i] > arr[j]){
				if (max < dp_down[j]){
					max = dp_down[j];
				}
			}
		}
		dp_down[i] = max + 1;
	}
	priority_queue <int> pq;
	for (int i = 0; i < cnt; i++){
		pq.push(dp_up[i] + dp_down[i] - 1);
	}
	cout << pq.top();
}