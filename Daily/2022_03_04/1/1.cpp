#include <cstring>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map <char, vector<char> > aft;
unordered_map <char, char> bf;
char skills[100] = {0};

void solution(int c, string ans){
	if (aft[c].size() == 0){
		cout << ans << "\n";
	}
	else{
		for(int i = 0; i < aft[c].size(); i++){
			solution(aft[c][i], ans + " " + aft[c][i]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	vector <int> skill;
	getline(cin, str);
	for(int i = 0; i < str.length(); i++){
		if (str[i] != ' '){
			skill.push_back(str[i]);
		}
	}
	int cnt;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		char c1, c2;
		cin >> c1 >> c2;
		aft[c1].push_back(c2);
		bf[c2] = c1;
	}
	for(int i = 0; i < skill.size(); i++){
		if (bf.count(skill[i]) == 0){
			string tmp = "";
			tmp += skill[i];
			solution(skill[i], tmp);
		}
	}
}
//8mins 46sec