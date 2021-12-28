#include <iostream>
#include <vector>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector <long long> vec;
	int N;
	long long M, num, maxy;
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> num;
		if (maxy < num)
			maxy = num;
		vec.push_back(num);
	}
	long long start = 1;
	long long end = maxy;
	long long ret = 0;
	while (start <= end){
		long long mid = (end + start) / 2;
		long long sum = 0;
		for(int i = 0; i < N; i++){
			if (vec[i] - mid > 0)
				sum += vec[i] - mid;
		}
		if (sum >= M){
			if (ret < mid)
				ret = mid;
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	cout << ret;
}