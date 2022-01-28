#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M, E, num;
	int start_ptr, end_ptr;
	int flag = 1;
	cin >> N >> M >> E;
	vector <int> peanuts;
	for(int i = 0; i < N; i++){
		cin >> num;
		if (num > E && flag){
			peanuts.push_back(E);
			start_ptr = i - M;
			end_ptr = i + M;
			flag = 0;
		}
		if (num == E)
			M--;
		else
			peanuts.push_back(num);
	}
	if (start_ptr < 0)
		start_ptr = 0;
	if (end_ptr >= peanuts.size())
		end_ptr = peanuts.size() - 1;
	int len = INT_MAX;
	for(int i = 0; i < end_ptr - start_ptr - M + 1; i++){
		len = min(len, peanuts[i + M] - peanuts[i]);
	}
	cout << len << "\n";
}