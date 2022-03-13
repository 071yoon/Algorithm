#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

bool compare(int a, int b){
	return a > b;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int myos, num;
	cin >> myos;
	vector <int> vec;
	for(int i = 0; i < myos; i++){
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end(), compare);	
	for(int i = 0; i < vec.size(); i++){
		vec[i] += i + 1;
	}
	cout << *max_element(vec.begin(), vec.end()) + 1 << "\n";
}
/*
2 3 4 4 

4 4 3 2
1 2 3 4
5 6 6 6 => 7

39 39 38 35 20 9
1  2  3  4  5  6
40 41 41 39 25 15 => 42
*/