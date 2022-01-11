#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int hear, listen;
	string str_tmp;
	cin >> hear >> listen;
	map <string, int> people;
	map <string, int> ret;
	for(int i = 1; i <= hear; i++){
		cin >> str_tmp;
		people.insert(make_pair(str_tmp, i));
	}
	int int_ret = 0;
	for(int i = 0; i < listen; i++){
		cin >> str_tmp;
		if (people[str_tmp]){
			int_ret++;
			ret.insert(make_pair(str_tmp, i));
		}
	}
	cout << int_ret << "\n";
	map <string, int>::iterator iter;
	for(iter = ret.begin(); iter != ret.end(); iter++){
		cout << iter->first << "\n";
	}
}