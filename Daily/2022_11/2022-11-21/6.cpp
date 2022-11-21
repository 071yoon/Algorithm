#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>
using namespace std;

int main() {
	string inputs;
	// input until enter
	getline(cin, inputs);

	// split string by space
	stringstream ss(inputs);
	string temp;
	set<int> s;
	while (ss >> temp) {
		s.insert(stoi(temp));
	}

	// get min difference between sets
	int min = 2e9;
	int prev = 0;
	int cur = 0;
	for (auto it = s.begin(); it != s.end(); it++) {
		auto next = it;
		next++;
		if (next != s.end()) {
			int diff = *next - *it;
			if (diff < min) {
				prev = *it;
				cur = *next;
				min = diff;
			}
		}
	}
	cout << prev << " " << cur << "\n";
	return 0;
}