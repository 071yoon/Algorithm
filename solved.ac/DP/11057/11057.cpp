
#include <iostream>
using namespace std;

int dp[10] = {0};

int sum(int num){
	int sum = 0;
	for(int i = num; i < 10; i++){
		sum += dp[i];
	}
	return (sum);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for(int i = 0; i < 10; i++)
		dp[i] = 1;
	int num;
	cin >> num;
	for(int i = 2; i <= num; i++){
		for(int j = 0; j < 10; j++){
			dp[j] = sum(j) % 10007;
		}
	}
	cout << sum(0) % 10007 << "\n";
}
/*
#include <iostream>
using namespace std;


int main()
{

	int dp[10000][10] = {};
	int n;
	int sum = 0;

	cin >> n;

	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;
	for (int j = 2; j <= n; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int k = 0; k <= i; k++)
			{
				dp[j][i] += dp[j - 1][k];
			}
			dp[j][i] %= 10007;
		}
	}
	for (int i = 0; i < 10; i++)
		sum = (sum + dp[n][i]) %10007;

	cout << sum %10007;
}*/