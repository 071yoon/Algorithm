#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> my_vec;
int cnt;
void F(long long N, int X)
{
	if (N == 0)
		return ;
	F(N / X, X);
	my_vec.push_back(N % X);
}

long long change(int X){
	long long ret = 0;
	for(int i = 0; i < my_vec.size(); i++){
		ret = my_vec[i] + ret * 10;
	}
	return (ret);
}

long long find_max(int X){
	long long ret = 0;
	for(int i = 0; i < X; i++){
		ret = (X - 1 - i) + ret * 10;
	}
	return (ret);
}

int find_unique(long long ret, int X){
	bool arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	while(ret){
		if (ret % 10 >= X || arr[ret % 10])
			return (0);
		else
			arr[ret % 10] = 1;
		ret /= 10;
	}
	return (1);
}

long long change2(long long num, int X){
	long long ret = 0;
	long long mul = 1;
	while (num){
		ret = (num % 10) * mul + ret;
		mul = mul * X;
		num /= 10;
	}
	return (ret);
}

long long find_next(long long maxy, long long ret, int X){
	long long tmp = ret;
	if (ret > maxy)
		return (-1);
	else{
		bool arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		while(tmp){
			if (tmp % 10 >= X || arr[tmp % 10]){
				ret = find_next(maxy, ret + 1, X);
				return (ret);
			}
			else
				arr[tmp % 10] = 1;
			tmp /= 10;
		}
		return (ret);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long N, ret, maxy;
	int d;
	cin >> N >> d;
	F(N + 1, d);
	ret = change(d);
//	cout << ret << "\n";
	maxy = find_max(d);
//	cout << maxy << "\n";
	ret = find_next(maxy, ret, d);
//	cout << ret << "\n";
	if (ret == -1)
		cout << "-1\n";
	else{
		ret = change2(ret, d);
		cout << ret << "\n";
	}
}