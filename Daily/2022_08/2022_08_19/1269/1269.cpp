#include <iostream>
#include <set>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	set<int> a;

	int a_size, b_size;
	cin >> a_size >> b_size;
	int ret = a_size + b_size;
	for(int i = 0; i < a_size; i++){
		int a_val;
		cin >> a_val;
		a.insert(a_val);
	}
	for(int i = 0; i < b_size; i++){
		int b_val;
		cin >> b_val;
		if (a.find(b_val) != a.end())
			ret -= 2;
	}
	cout << ret << "\n";
}