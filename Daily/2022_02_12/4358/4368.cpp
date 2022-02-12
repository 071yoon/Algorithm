#include <map>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	int cnt = 0;
	map <string, float> people;
	while(getline(cin, str)){
		people[str]++;
		cnt++;
	}
	cout << fixed;
	cout.precision(4);
	for(auto it = people.begin(); it != people.end(); it++){
		double val = (it->second / cnt) * 100;
		cout << it->first << " " << val << "\n";
	}

}