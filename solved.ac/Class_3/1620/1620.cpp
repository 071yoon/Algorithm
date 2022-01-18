#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt, num, int_tmp;
	string str_tmp;
	cin >> cnt >> num;
	vector <string> vec(cnt);
	map <string, int> mp1; 
	for(int i = 0; i < cnt; i++){
		cin >> str_tmp;
		vec[i] = str_tmp;
		mp1.insert(make_pair(str_tmp, i));
	}
	for(int i = 0; i < num; i++){
		cin >> str_tmp;
		if (str_tmp[0] >= '1' && str_tmp[0] <= '9'){
			int_tmp = stoi(str_tmp);
			cout << vec[int_tmp - 1] << "\n";
		}
		else{
			cout << mp1[str_tmp] + 1 << "\n";
		}
	}
}