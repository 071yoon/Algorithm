#include <iostream>
#include <vector>
using namespace std;

vector <int> root;

int finder(int a){
	if (root[a] == a)
		return a;
	else{
		root[a] = finder(root[a]);
		return (root[a]);
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

	int V, E;
	cin >> V >> E;
	for(int i = 0; i <= V; i++)
		root.push_back(i);
	int what, a, b;
	for(int i = 0; i < E; i++){
		cin >> what >> a >> b;
		if (what == 0){
			union_(a, b);
		}
		else{
			if (finder(a) == finder(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}