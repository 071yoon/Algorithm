#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void solution(){
	int cnt, num, mid = 0;
	cin >> cnt;
	priority_queue <int, vector<int>, greater<int> > right;
	priority_queue <int> left;
	vector <int> ans;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		if (i == 0){
			mid = num;
		}
		else{
			if (num >= mid) right.push(num);
			else left.push(num);
		}
		if (i % 2 == 0){
			if (left.size() > right.size()){
				right.push(mid);
				mid = left.top();
				left.pop();
			}
			else if(right.size() > left.size()){
				left.push(mid);
				mid = right.top();
				right.pop();
			}
			ans.push_back(mid);
		}
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
		if ((i + 1) % 10 == 0) cout << "\n";
	}
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int test_case;
	cin >> test_case;
	while(test_case--){
		solution();
	}
}