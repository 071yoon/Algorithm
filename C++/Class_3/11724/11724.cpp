#include <iostream>
#include <vector>
using namespace std;

vector <int> arr[1001];
bool visited[1001];

void DFS(int node){
	visited[node] = 1;
	for(int i = 0; i < arr[node].size(); i++){
		if (!visited[arr[node][i]])
			DFS(arr[node][i]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int nodes, cnt, num1, num2, ret;
	cin >> nodes >> cnt;
	ret = 0;
	for(int i = 0; i < cnt; i++){
		cin >> num1 >> num2;
		arr[num1].push_back(num2);
		arr[num2].push_back(num1);
	}
	for(int i = 1; i <= nodes; i++){
		if (arr[i].empty())
			ret++;
		else if (visited[i])
			continue;
		else if (arr[i].front()){
			DFS(i);
			ret++;
		}
	}
	cout << ret << "\n";
}