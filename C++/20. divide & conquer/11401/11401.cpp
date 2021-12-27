#include<iostream>
#include<cmath>
using namespace std;

long long N, K, A, B, half;
long long mod = 1000000007;

long long solve(int x)
{
	if (x == 0) 
		return 1;
	if (x % 2 == 1) 
		return (B * solve(x - 1) % mod);
	else {
		half = solve(x / 2);
		return half * half % mod;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> K;
	A = 1;
	for (int i = N; i >= N - K + 1; i--) 
		A = (A * i) % mod;// A = N*(N-1)* .... *(N-K+1)
	B = 1;
	for (int i = 1; i <= K; i++) 
		B = (B * i) % mod;	// B = K!
	B = solve(mod - 2);	// B = K!
	cout << A * B % mod;
	            
}