#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int lines, cnt, num1, num2;
	int guitar_six = INT_MAX;
	int guitar_one = INT_MAX;
	cin >> lines >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> num1 >> num2;
		guitar_six = min(num1, guitar_six);
		guitar_one = min(num2, guitar_one);
	}
	int six, one;
	six = lines / 6;
	one = lines % 6;
	int total;
	if (6 * guitar_one <= guitar_six)
		total = lines * guitar_one;
	else if (one * guitar_one < guitar_six)
		total = six * guitar_six + one * guitar_one;
	else
		total = (six + 1) * guitar_six;
	cout << total << "\n";

}