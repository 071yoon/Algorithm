#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int dir, line;
	int dirs[4] = {0};
	pair<int, int> lines[6];
	int mul;
	cin >> mul;
	for(int i = 0; i < 6; i++){
		cin >> dir >> line;
		lines[i] = make_pair(dir - 1, line);
		dirs[dir - 1] += line;
	}
	int minus = 0;
	int plus = dirs[0] * dirs[2];
	for(int i = 0; i < 6; i++){
		if (lines[i].second < dirs[lines[i].first] && 
			lines[(i + 1) % 6].second < dirs[lines[(i + 1) % 6].first] && 
			lines[(i + 2) % 6].second < dirs[lines[(i + 2) % 6].first] &&
			lines[(i + 3) % 6].second < dirs[lines[(i + 3) % 6].first]){ 
			// cout << lines[(i + 1) % 6].second << " " << lines[(i + 2) % 6].second << "\n";
			minus = lines[(i + 1) % 6].second * lines[(i + 2) % 6].second;
			// cout << "minus is " << minus << endl;
			break;
		}
	}
	cout << (plus - minus) * mul << endl;
}