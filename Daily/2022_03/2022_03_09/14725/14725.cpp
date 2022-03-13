#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

struct Trie {
	Tire(){}
	~Trie(){
		for(auto it = m.begin(); it != m.end(); it++){
			delete (*it).second;
		}
	}
	void insert(vector<string> &v, int index){
		if (v.size() == index) return ;
		if (m.count(v[index]) == 0){
			m.insert(make_pair(v[index], new Trie()));
			m[v[index]]->insert(v, index + 1);
		}
		else{
			m[v[index]]->insert(v, index + 1);
		}
	}
	void find(int depth){
		for(auto it = m.begin(); it != m.end(); it++){
			for(int i = 0; i < depth; i++){
				cout << "--";
			}
			cout << (*it).first << "\n";
			(*it).second->find(depth + 1);
		}
	}
	map<string, Trie*> m;
};

int n; string val;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	Trie *root = new Trie();
	for(int i = 0; i < n; i++){
		int k;
		cin >> k;
		vector <string> v;
		for(int j = 0; j < k; j++){
			cin >> val;
			v.push_back(val);
		} 
		root->insert(v, 0);
	}
	root->find(0);
	delete root;
}


