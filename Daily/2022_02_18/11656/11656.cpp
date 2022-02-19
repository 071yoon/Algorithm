#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	cin >> str;
	vector <string> vec;
	for(int i = 0; i < str.size(); i++){
		string tmp = str.substr(i, str.size());
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end());
	for(int i = 0; i < vec.size(); i++){
		cout << vec[i] << "\n";
	}
}