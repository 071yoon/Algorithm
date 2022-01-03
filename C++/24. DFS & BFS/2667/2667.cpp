#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int cnt, vec_cnt;
int arr[27][27] = {0};
vector <int> vec;

int check(int x, int y){
	if (arr[x][y + 1] || arr[x][y - 1] || arr[x + 1][y] || arr[x - 1][y])
		return (1);
	else
		return (0);
}

void DFS(int y, int x){
	arr[y][x] = 0;
	vec[vec_cnt]++;
	if (arr[y][x + 1])
		DFS(y, x + 1);
	if (arr[y][x - 1])
		DFS(y, x - 1);
	if (arr[y - 1][x])
		DFS(y - 1, x);
	if (arr[y + 1][x])
		DFS(y + 1, x);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> cnt;
	vec_cnt = 0;
	string str;
	for(int y = 1; y <= cnt; y++){
		cin >> str;
		for(int x = 1; x <= cnt; x++){
			arr[y][x] = str[x - 1] - '0';
		}
	}
	for(int y = 1; y <= cnt; y++){
		for(int x = 1; x <= cnt; x++){
			if (arr[y][x]){
				vec.push_back(0);
				DFS(y, x);
				vec_cnt++;
			}
		}
	}
	sort(vec.begin(), vec.end());
	cout << vec.size() << "\n";
	for(int i = 0; i < vec.size(); i++){
		cout << vec[i] << "\n";
	}
}