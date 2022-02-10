#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool visited[201] = {0};
int answer = 0;
void dfs(int target, vector<vector<int> > &computers){
	visited[target] = 1;
	for(int i = 0; i < computers[target].size(); i++){
		if (computers[target][i] == 1 && !visited[i]){
			dfs(i, computers);
		}
	}
}


int solution(int n, vector<vector<int> > computers) {
	for(int i = 0; i < computers.size(); i++){
		if (!visited[i]){
			answer++;
			dfs(i, computers);
		}
	}
    return answer;
}

int main(){
	vector<vector<int> > computers;
	vector<int> a;
	a.push_back(1);
	a.push_back(1);
	a.push_back(0);
	vector<int> b;
	b.push_back(1);
	b.push_back(1);
	b.push_back(0);
	vector <int> c;
	c.push_back(0);
	c.push_back(0);
	c.push_back(1);
	computers.push_back(a);
	computers.push_back(b);
	computers.push_back(c);
	cout << solution(3, computers) << "\n";
}