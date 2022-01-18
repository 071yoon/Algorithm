#include<iostream>
#include<algorithm>
using namespace std;

int cnt, kg;
int DP[101][100001];
int items[101][2];

int main()
{
	cin >> cnt >> kg;

	for (int i = 1; i <= cnt; i++)
		cin >> items[i][0] >> items[i][1];
	for (int i = 1; i <= cnt; i++){
		for (int j = 1; j <= kg; j++){
			if (j - items[i][0] >= 0) 
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - items[i][0]] + items[i][1]);
			else 
				DP[i][j] = DP[i - 1][j];
		}
	}
	cout << DP[cnt][kg];
}