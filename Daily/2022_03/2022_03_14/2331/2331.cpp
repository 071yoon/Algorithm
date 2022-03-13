#include <cmath>
#include <iostream>
using namespace std;

int visited[300001] = {0};
int num1, num2;

void dfs(int num){
	visited[num]++;
	if (visited[num] == 3) return ;
	int sum = 0;
	while(num){
		sum += pow((num % 10), num2);
		num /= 10;
	}
	dfs(sum);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int ans = 0;
	cin >> num1 >> num2;
	dfs(num1);
	for(int i = 0; i < 300001; i++){
		if (visited[i] == 1) ans++;
	}
	cout << ans << "\n";
}