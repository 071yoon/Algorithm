#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

vector <int> primes;
int	isprime(int nb)
{
	int	i;
	int	num;

	num = nb;
	if (num < 2)
		return (0);
	if (num == 2)
		return (1);
	i = 2;
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int num;
	cin >> num;
	if (num == 1){
		cout << "0\n";
		return (0);
	}
	for(int i = 2; i <= num; i++){
		if (isprime(i))
			primes.push_back(i);
	}
	int sum = 0; int start = 0; int end = 0; int ret = 0;
	while (start <= end) {
		sum += primes[end];
		if (sum >= num) {
			if (sum == num)
				ret++;
			sum -= primes[start++];
			sum -= primes[end];
		}
		else if (end == primes.size() - 1) 
			break;
		else 
			end++;
	}
	cout << ret << "\n";
}
