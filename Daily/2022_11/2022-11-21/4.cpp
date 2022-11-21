#include <iostream>
#include <map>
using namespace std;

int main() {
	string main_pw;
	int n;
	cin >> main_pw;
	cin >> n;
	map <string, string> m;
	for(int i = 0; i < n; i++) {
		string room_id, room_pw;
		cin >> room_id >> room_pw;
		m[room_id] = room_pw;
	}
	string inputs;
	cin >> inputs;
	return 0;
}