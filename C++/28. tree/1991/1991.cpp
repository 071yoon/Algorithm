#include <iostream>
#include <vector>

using namespace std;

vector <pair <int, int> > tree[26];//<node, (-1=left, 1=right, 0=parent)>
int root;
void front_print(int node){
	cout << char(node + 'A');
	for(int i = 0; i < tree[node].size(); i++){
		if (tree[node][i].second == -1)
			front_print(tree[node][i].first);
	}
	for(int i = 0; i < tree[node].size(); i++){
		if (tree[node][i].second == 1)
			front_print(tree[node][i].first);
	}
}

void mid_print(int node){
	for(int i = 0; i < tree[node].size(); i++){
		if (tree[node][i].second == -1)
			mid_print(tree[node][i].first);
	}
	cout << char(node + 'A');
	for(int i = 0; i < tree[node].size(); i++){
		if (tree[node][i].second == 1)
			mid_print(tree[node][i].first);
	}
}

void end_print(int node){
	for(int i = 0; i < tree[node].size(); i++){
		if (tree[node][i].second == -1)
			end_print(tree[node][i].first);
	}
	for(int i = 0; i < tree[node].size(); i++){
		if (tree[node][i].second == 1)
			end_print(tree[node][i].first);
	}
	cout << char(node + 'A');
}

void find_root(int node){
	int flag = 0;
	for(int i = 0; i < tree[node].size(); i++){
		if (tree[node][i].second == 0){
			flag = 1;
			find_root(tree[node][i].first);
		}
	}
	if (flag == 0)
		root = node;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt;
	char parent, left, right;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> parent >> left >> right;
		if (left != '.'){
			tree[(int)parent - 'A'].push_back(make_pair((int)left - 'A', -1));
			tree[(int)left - 'A'].push_back(make_pair((int)parent - 'A', 0));
		}
		if (right != '.'){
			tree[(int)parent - 'A'].push_back(make_pair((int)right - 'A', 1));
			tree[(int)right - 'A'].push_back(make_pair((int)parent - 'A', 0));
		}
	}
	find_root(0);
//	cout << "root : " << char(root + 'A') << "\n";
	front_print(root);
	cout << "\n";
	mid_print(root);
	cout << "\n";
	end_print(root);
	cout << "\n";

}