#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long N,C,W[31],ans;
vector<long long> group1;
vector<long long> group2;

void dfs(int s, int e, vector<long long>& v, long long sum)
{
	if(s > e){
		v.push_back(sum);
		return;
	}
	else{
		dfs(s+1, e, v, sum);
		dfs(s+1, e, v, sum+W[s]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> C;
	
	for(int i = 0; i < N; i++){
		cin >> W[i];
	}
	
	// 반으로 나눠서 경우의수 저장  
	dfs(0, N/2, group1, 0);
	dfs(N/2 + 1, N-1, group2, 0);
	sort(group2.begin(), group2.end());
	
	
	for(int i = 0; i < group1.size(); i++)
		ans += upper_bound(group2.begin(), group2.end(), C - group1[i]) - group2.begin();
	
	cout << ans << endl;
}