#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector <int> vec;
	vector <int> ans;
	int cnt, k;
	cin >> cnt >> k;
	for(int i = 0; i < cnt; i++)
		vec.push_back(i + 1);
	int index = 0;
	cout << "<";
	for(int i = 0; i < cnt; i++){
		index += k - 1;
		while (index >= vec.size()){
			index -= vec.size();
		}
		if (vec.size() != 1)
			cout << vec[index] << ", ";
		else
			cout << vec[index];
		vec.erase(vec.begin() + index);
	}
	cout << ">\n";
}
