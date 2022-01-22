#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	vector <int> vec(3);
	cin >> vec[0] >> vec[1] >> vec[2];
	sort(vec.begin(), vec.end());
	cout << vec[1];
}