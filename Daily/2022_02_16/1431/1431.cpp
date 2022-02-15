#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(string a, string b){
	if (a.length() != b.length())
		return a.length() < b.length();
	int a_int = 0, b_int = 0;
	for(int i = 0; i < a.length(); i++){
		if (a[i] >= '0' && a[i] <= '9'){
			a_int += a[i] - '0';
		}
		if (b[i] >= '0' && b[i] <= '9'){
			b_int += b[i] - '0';
		}
	}
	if (a_int != b_int){
		return a_int < b_int;
	}
	else
		return a < b;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt;
	string str;
	vector <string> vec;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> str;
		vec.push_back(str);
	}
	sort(vec.begin(), vec.end(), compare);
	for(int i = 0; i < vec.size(); i++)
		cout << vec[i] << "\n";
}