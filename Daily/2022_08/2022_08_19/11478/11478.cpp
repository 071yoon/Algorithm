#include <iostream>
#include <set>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	set<string> my_set;

	string str;
	cin >> str;
	for(int i = 0; i < str.size(); i++){
		string tmp = "";
		for(int j = i; j < str.size(); j++){
			tmp += str[j];
			my_set.insert(tmp);
		}
	}
	cout << my_set.size() << "\n";
}