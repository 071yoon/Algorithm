#include <iostream>
#include <queue>

using namespace std;
int N, M, V, num1, num2;
int arr1[1001][1001] = {0};
int arr2[1001][1001] = {0};
int visited[1001] = {0};
queue <int> que;

int BFS(){
	int tmp = que.front();
	que.pop();
	cout << tmp << " ";
	for(int i = 1; i <= N; i++){
		if (arr2[i][tmp])
			arr2[i][tmp] = 0;
	}
	for(int i = 1; i <= N; i++){
		if(arr2[tmp][i] && !visited[i]){
			que.push(i);
			visited[i] = 1;
		}
	}
	return (0);
}
/* 1-> 2 -> 
1 2
1 3
1 4
//2 1
2 4
//3 1
3 4
//4 1
4 2
4 3
*/
int DFS(int V){
	cout << V << " ";
	for(int i = 1; i <= N; i++){
		if (arr1[i][V])
			arr1[i][V] = 0;
	}
	for(int i = 1; i <= N; i++){
		if (arr1[V][i])
			DFS(i);
	}
	return (0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		cin >> num1 >> num2;
		arr1[num1][num2] = 1;
		arr1[num2][num1] = 1;
		arr2[num1][num2] = 1;
		arr2[num2][num1] = 1;
	}
	DFS(V);
	cout << "\n";
	que.push(V);
	visited[V] = 1;
	while(!que.empty())
		BFS();
	return (0);
}