#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, A_sz, B_sz, num;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		int ret = 0;
		vector <int> A;
		vector <int> B;
		cin >> A_sz >> B_sz;
		for(int j = 0; j < A_sz; j++){
			cin >> num;
			A.push_back(num);
		}
		for(int j = 0; j < B_sz; j++){
			cin >> num;
			B.push_back(num);
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		for(int j = 0; j < A_sz; j++){
			for(int k = 0; k < B_sz; k++){
				if (A[j] > B[k]){
					ret++;
				}
				else
					break;
			}
		}
		cout << ret << "\n";
	}
}