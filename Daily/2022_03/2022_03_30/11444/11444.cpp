#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<long long> > matrix;
const long long mod = 1000000007;

long long n;

matrix mul(matrix &a, matrix &b){
	matrix c(2, vector<long long>(2));
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= mod;
		}
	}
	return c;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	vector <long long> one_zero;
	one_zero.push_back(1);
	one_zero.push_back(0);
	vector <long long> zero_one;
	zero_one.push_back(0);
	zero_one.push_back(1);
	vector <long long> one_one;
	one_one.push_back(1);
	one_one.push_back(1);
	matrix ans;
	ans.push_back(one_zero);
	ans.push_back(zero_one);
	matrix a;
	a.push_back(one_one);
	a.push_back(one_zero);
	while (n > 0){
		if (n % 2){
			ans = mul(ans, a);
		}
		a = mul(a, a);
		n /= 2;
	}
	cout << ans[0][1] << "\n";
}