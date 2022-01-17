#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int lst, cnt;
	cin >> lst >> cnt;
	string web, pass;
	map <string, string> mp;
	while(lst--){
		cin >> web >> pass;
		mp.insert(make_pair(web, pass));
	}
	map <string, string>::iterator iter;
	while(cnt--){
		cin >> web;
		iter = mp.find(web);
		cout << iter->second << "\n";
	}

}