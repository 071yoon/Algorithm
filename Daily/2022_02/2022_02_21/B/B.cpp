#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int num1, num2, num3;
	cin >> num1 >> num2;
	vector <int> vec;
	for(int i = 0; i < num1; i++){
		cin >> num3;
		vec.push_back(num3);
	}
	int ret = 0;
	for(int i = 0; i < num2; i++){
		ret += vec[i];
	}
	int final = ret;
	for(int i = 1; i < num1; i++){
		int tmp = ret;
		tmp -= vec[i - 1];
		tmp += vec[(i + num2 - 1) % num1];
		final = max(tmp, final);
		ret = tmp;
	}
	cout << final << "\n";
}