#include <cmath>
#include <iostream>
using namespace std;

int sz;

bool is_prime(int num){
	if (num == 1 || num == 0){
		return (0);
	}
	if (num == 2) return (1);
	for(int i = 2; i * i <= num; i++){
		if (num % i == 0){
			return (0);
		}
	}
	return (1);
}

void recur(int num, int cnt){
	if (cnt == sz){
		cout << num << "\n";
		return ;
	}
	for(int i = 1; i < 10; i += 2){
		if (is_prime(num * 10 + i))
			recur(num * 10 + i, cnt + 1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> sz;
	int first[4] = {2, 3, 5, 7};
	for(int i = 0; i < 4; i++){
		recur(first[i], 1);
	}
}