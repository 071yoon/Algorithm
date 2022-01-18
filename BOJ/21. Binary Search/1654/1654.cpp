#include <iostream>
#include <vector>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int K, N;
	long long length;
	cin >> K >> N;
	long long maxy;
	vector <long long> vec;
	for (int i = 0; i < K; i++){
		cin >> length;
		if (maxy < length)
			maxy = length;
		vec.push_back(length);
	}
	long long start, end;
	long long ret;
	start = 1; end = maxy;
	while (start <= end){
		long long mid = (start + end) / 2;
		int sum = 0;
		for(int i = 0; i < K; i++){
			sum += vec[i] / mid;
		}
		if (sum >= N){
			ret = mid;
			start = mid + 1;
		}
		else{
			end = mid - 1;
		}
	}
	cout << ret;
}