#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void recur(int num, int from, int by, int to) {
    if (num == 1) {
        cout << from << " " << to << "\n";
        return;
    }
    recur(num - 1, from, to, by);
    cout << from << " " << to << "\n";
    recur(num - 1, by, from, to);
}

int main(){
	int N;
	cin >> N;

	string a = to_string(pow(2, N));
	int x = a.find('.');
	a = a.substr(0, x);
    a[a.length() - 1]--;
    cout << a << "\n";

    if (N > 20) return 0;
    recur(N, 1, 2, 3);
}