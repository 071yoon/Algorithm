#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt, num;
	cin >> cnt;
	vector <int> A;
	vector <int> B;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		A.push_back(num);
	}
	for(int i = 0; i < cnt; i++){
		cin >> num;
		B.push_back(num);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int ret = 0;
	for(int i = 0; i < cnt; i++){
		ret += A[i] * B[cnt - 1 - i];
	}
	cout << ret << "\n";
}