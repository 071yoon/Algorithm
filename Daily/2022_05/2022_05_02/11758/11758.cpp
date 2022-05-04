#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if ((x1*y2 - x2*y1 + x2*y3 - x3*y2 + x3*y1 - x1*y3) / 2 > 0)
        cout << '1' << '\n';
    else if ((x1*y2 - x2*y1 + x2*y3 - x3*y2 + x3*y1 - x1*y3) / 2 < 0)
        cout << "-1" << '\n';
    else
        cout << '0' << '\n';
}