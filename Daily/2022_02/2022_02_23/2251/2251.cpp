#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int A, B, C;
bool visited[201][201][201] = {0};
vector <int> ans;

void dfs(int bA, int bB, int bC){
	if (visited[bA][bB][bC])
		return ;
	visited[bA][bB][bC] = 1;
	if (bA == 0){
		ans.push_back(bC);
	}
	//A -> B
	if (bA + bB > B)
		dfs(bA + bB - B, B , bC);
	else
		dfs(0, bA + bB, bC);
	//B -> A
	if (bB + bA > A)
		dfs(A, bA + bB - A, bC);
	else
		dfs(bA + bB, 0, bC);
	// C -> A
	if (bC + bA > A)
		dfs(A, bB, bC + bA - A);
	else
		dfs(bC + bA, bB, 0);
	//C -> B
	if (bC + bB > B)
		dfs(bA, B, bC + bB - B);
	else
		dfs(bA, bC + bB, 0);
	dfs(bA, 0, bB + bC); //B -> C
	dfs(0, bB, bA + bC); //A -> C
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> A >> B >> C;
	dfs(0, 0, C);
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
}
/*
처음 그대로
처음에 B 로 보내면 
	1. C - B
	2. 남은거를 A 로 보내고 
C - B


*/