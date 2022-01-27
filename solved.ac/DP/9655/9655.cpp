#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int num;
	cin >> num;
	if (num % 2 == 0)
		cout << "CY\n";
	else
		cout << "SK\n";
	
}