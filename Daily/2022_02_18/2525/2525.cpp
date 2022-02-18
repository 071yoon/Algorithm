#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int hr, min;
	cin >> hr >> min;
	int time; cin >> time;
	min += time;
	while (min >= 60){
		min -= 60;
		hr++;
	}
	hr %= 24;
	cout << hr << " " << min << "\n";
}