#include <iostream>
using namespace std;

char input[10000][11];

struct TRIE {
	bool finish;
	TRIE *node[10];
	TRIE(){
		finish = false;
		for(int i = 0; i < 10; i++){
			node[i] = NULL;
		}
	}
	void insert(char *str){
		if (*str == '\0'){
			finish = true;
			return ;
		}
		int cur = *str - '0'; 
		if (node[cur] == NULL) node[cur] = new TRIE();
		node[cur]->insert(str + 1);
	}
	bool find(char *str){
		if (*str == '\0'){
			return false;
		}
		if (finish == true) return true;
		int cur = *str - '0';
		if (node[cur] == NULL) return false;
		return (node[cur]->find(str + 1));
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, t;
	cin >> t;
	while(t--){
		cin >> n;
		TRIE *trie = new TRIE();
		for(int i = 0; i < n; i++){
			cin >> input[i];
			trie->insert(input[i]);
		}
		int flag = 1;
		for(int i = 0; i < n; i++){
			if (trie->find(input[i])){
				cout << "NO\n";
				flag = 0;
				break ;
			}
		}
		if (flag) cout << "YES\n";
	}
}