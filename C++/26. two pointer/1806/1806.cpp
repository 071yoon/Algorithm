#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, s;
	cin >> n >> s;
	vector <int> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int min_len = INT_MAX; int sum = 0; int start = 0; int end = 0;
	while (start <= end) {
		if (sum >= s) {
			min_len = min(min_len, end - start);
			sum -= arr[start];
			start++;
		}
		else if (end == n) 
			break;
		else {
			sum += arr[end];
			end++;
		}
	}
	if (min_len == INT_MAX)
		cout << "0\n";
	else
		cout << min_len << "\n";
}