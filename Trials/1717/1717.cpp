#include <iostream>
using namespace std;

int parents[1000001];

int find_root(int a){
	if (parents[a] == a)
		return (a);
	else{
		parents[a] = find_root(parents[a]);
		return (parents[a]);
	}
}

void set_root(int a, int b){
	int parent_a = find_root(a);
	int parent_b = find_root(b);
	if (parent_a > parent_b)
		parents[parent_a] = parents[parent_b];
	else
		parents[parent_b] = parents[parent_a];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int test, a, b;
	for(int i = 1; i <= n; i++){
		parents[i] = i;
	}

	for(int i = 0; i < m; i++){
		cin >> test >> a >> b;
		if (test == 0){
			set_root(a, b);
		}
		else{
			if (find_root(a) == find_root(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}