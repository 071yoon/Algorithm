#include <iostream>
#include <algorithm>
using namespace std;
int home[200001];

int binarySearch(int n, int c){
	int end = home[n - 1];//last
	int start = 1;//first
	int ans = 0;
	while(start <= end){
		int cnt = 1;
		int mid = (start + end) / 2;//length we want
		int starter = home[0];
		for(int i = 1; i < n; i++){
			if(home[i] - starter >= mid){
				starter = home[i];
				cnt++;
			}
		}
		//start points to last
		if(cnt >= c) {
			ans = mid;
			start = mid + 1;
		}
		else 
			end = mid - 1;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n,c;
	cin >> n >> c;

	for(int i = 0; i < n; i++) 
		cin >> home[i];
	sort(home,home + n);
	cout << binarySearch(n,c);
}