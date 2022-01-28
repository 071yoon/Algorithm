#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector <pair<int, int> > skillset;
vector <int> skills[1000];
map <char, int> m;
map <int, char> m2;

void dfs(int key, string path){
	if (skills[key].size() == 0 && path.length() != 1){
		for(int i = 0; i < path.length(); i++)
			cout << path[i] << " ";
		cout << "\n";
	}
	else{
		for(int i = 0; i < skills[key].size(); i++){
			int next = skills[key][i];
			dfs(next, path + m2[next]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	int cnt = 0;
	getline(cin, str);
	for(int i = 0; i < str.length(); i++){
		if(isalpha(str[i])){
			m[str[i]] = cnt;
			m2[cnt] = str[i];
			skillset.push_back(make_pair(cnt++, 0));
		}
	}
	int num;
	cin >> num;
	char skill1, skill2;
	for(int i = 0; i < num; i++){
		cin >> skill1 >> skill2;
		skills[m[skill1]].push_back(m[skill2]);
		skillset[m[skill2]].second++;
	}
	for(int i = 0; i < cnt; i++){
		if (skillset[i].second == 0){
			string path;
			path += m2[i];
			dfs(i, path);
		}
	}
}