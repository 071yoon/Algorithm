#include <iostream>
using namespace std;

bool isprime(int num){
	if (num < 2)
		return (false);
	for(int i = 2; i * i <= num; i++){
		if (num % i == 0)
			return (false);
	}
	return (true);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int num;
	while (1){
		cin >> num;
		if (num == 0)
			break ;
		int flag = 1;
		for (int i = 2; i <= num / 2; i++){
			if (isprime(i) && isprime(num - i)){
				cout << num << " = " << i << " + " << num - i << "\n";
				flag = 0;
				break ;
			}
		}
		if (flag)
			cout << "Goldbach's conjecture is wrong.\n";
	}
}