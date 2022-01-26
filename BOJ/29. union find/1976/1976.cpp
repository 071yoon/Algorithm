#include <iostream>
#include <vector>
using namespace std;

vector <int> root;

int finder(int num){
	if (root[num] == num)
		return (num);
	else{
		root[num] = finder(root[num]);
		return (root[num]);
	}
}

void union_(int a, int b){
	int root_a = finder(a);
	int root_b = finder(b);
	if (root_a > root_b)
		root[root_a] = root_b;
	else
		root[root_b] = root_a;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N;
	for(int i = 0; i <= N; i++)
		root.push_back(i);
	cin >> M;
	int num;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> num;
			if (i != j && num == 1){
				union_(i, j);
			}
		}
	}
	cin >> num;
	int ret = root[num];
	for(int i = 1; i < M; i++){
		cin >> num;
		if (ret != root[num]){
			cout << "NO\n";
			return (0);
		}
	}
	cout << "YES\n";
}