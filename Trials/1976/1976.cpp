#include <iostream>
#include <vector>
using namespace std;

int roots[201];

int finder(int node){
	if (roots[node] == node){
		return (node);
	}
	else{
		roots[node] = finder(roots[node]);
		return (roots[node]);
	}
}

void union_(int node1, int node2){
	int node1_root = finder(node1);
	int node2_root = finder(node2);
	if (node1_root < node2_root){
		roots[node2_root] = roots[node1_root];
	}
	else{
		roots[node1_root] = roots[node2_root];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	int num;

	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		roots[i] = i;
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> num;
			if (num && j >= i + 1){
				union_(i, j);
			}
		}
	}
	cin >> num;
	int tmp = finder(num);
	for(int i = 1; i < M; i++){
		cin >> num;
		if (tmp != finder(num)){
			cout << "NO\n";
			return(0) ;
		}
	}
	cout << "YES\n";
	
}