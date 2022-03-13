#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;

unordered_map <char, int> convert;
unordered_map <int, char> convert2;
int indexy;
vector <int> after[100];
int before[100] = {0};
vector <string> answers;

void do_loop(int cur, string tmp){
	tmp = tmp + convert2[cur] + " ";
	for(int i = 0; i < after[cur].size(); i++){
		do_loop(after[cur][i], tmp);
	}
	if (after[cur].size() == 0){
		answers.push_back(tmp);
		return ;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string all_skills;
	indexy = 1;
	getline(cin, all_skills);
	for(int i = 0; i < all_skills.length(); i++){
		if ((all_skills[i] >= 'a' && all_skills[i] <= 'z') || (all_skills[i] >= 'A' && all_skills[i] <= 'Z')){
			convert2[indexy] = all_skills[i];
			convert[all_skills[i]] = indexy;
			indexy++;
		}
	}
	int cnt;
	cin >> cnt;
	char bef, aft;
	for(int i = 0; i < cnt; i++){
		cin >> bef, cin >> aft;
		int bf = convert[bef];
		int af = convert[aft];
		after[bf].push_back(af);
		before[af] = bf;
	}
	for(int i = 1; i < indexy; i++){
		if (before[i] == 0){
			do_loop(i, "");
		}
	}
	for(int i = 0; i < answers.size(); i++){
		cout << answers[i] << "\n";
	}
}
//29mins 33sec