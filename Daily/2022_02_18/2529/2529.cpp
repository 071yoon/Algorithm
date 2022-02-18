#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

vector <char> vec;
vector <int> nums;
vector <vector<int> > total;
int cnt;
bool visited[10] = {0};
long long min_val = INT_MAX;
long long max_val = 0;

void dfs(int cntr, int index){
	if (cntr == cnt){
		total.push_back(nums);
		return ;
	}
	if (vec[index] == '<'){
		for(int i = nums[index] + 1; i < 10; i++){
			if (!visited[i]){
				visited[i] = 1;
				nums.push_back(i);
				dfs(cntr + 1, index + 1);
				visited[i] = 0;
				nums.pop_back();
			}
		}
	}
	else{
		for(int i = nums[index] - 1; i >= 0; i--){
			if (!visited[i]){
				visited[i] = 1;
				nums.push_back(i);
				dfs(cntr + 1, index + 1);
				visited[i] = 0;
				nums.pop_back();
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> cnt;
	char num;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		vec.push_back(num);
	}
	for(int i = 0; i < 10; i++){
		visited[i] = 1;
		nums.push_back(i);
		dfs(0, 0);
		visited[i] = 0;
		nums.pop_back();
	}
	sort(total.begin(), total.end());
	for(int i = 0; i < total[0].size(); i++){
		cout << total[total.size() - 1][i];
	}
	cout << "\n";
	for(int i = 0; i < total[0].size(); i++){
		cout << total[0][i];
	}
	cout << "\n";
}