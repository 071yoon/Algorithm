#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool is_prime(int num){
	if (num == 2) return true;
	for(int i = 2; i <= sqrt(num); i++){
		if(num % i == 0)
			return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	int num = 2, prev = 2;
	while (1){
		num += 1;
		while (!is_prime(num))
			num++;
		if (num * prev > N){
			cout << num * prev << "\n";
			return (0);
		}
		prev = num;
	}
}