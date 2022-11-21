#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

map <string, bool> m;

int main() {
	int level, cnt;
	string str;

	cin >> level >> cnt;
	cin >> str;

	m["1"] = 0;
	vector<string> v;
    stringstream ss(str);
    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        v.push_back(substr);
    }

	return 0;
}