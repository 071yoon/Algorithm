#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string org;
	vector <string> tags;
	vector <string> words;
	getline(cin, org);
	int tag = 0; int word = 0;
	for(int i = 0; i < org.length(); i++){
		if (org[i] == ' '){
			cout << " ";
			continue ;
		}
		if (org[i] == '<'){
			tags.push_back("<");
			i++;
			while (org[i] != '>'){
				tags[tag] += org[i];
				i++;
			}
			tags[tag] += ">";
			cout << tags[tag];
			tag++;
		}
		else{
			words.push_back("");
			while(org[i] != '<' && i != org.length() && org[i] != ' '){
				words[word] += org[i];
				i++;
			}
			reverse(words[word].begin(), words[word].end());
			cout << words[word];
			i--;
			word++;
		}
	}
}
//15 mins