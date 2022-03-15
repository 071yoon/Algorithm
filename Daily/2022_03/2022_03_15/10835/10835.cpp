#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int cnt;
int A[2000];
int B[2000];
int piles[2000][2000] = {0};

void inputs(){
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> A[i];
	}
	for(int i = 0; i < cnt; i++){
		cin >> B[i];
	}
}

int solution(int left, int right){
	if (left >= cnt || right >= cnt) return (0);
	int &tmp = piles[left][right];
	if (tmp != -1) return tmp;
	tmp = 0;
	if (A[left] > B[right]) tmp = tmp + B[right] + solution(left, right + 1);
	else tmp = tmp + max(solution(left + 1, right), solution(left + 1, right + 1));
	return tmp;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
	memset(piles, -1, sizeof(piles));
	cout << solution(0, 0) << "\n";
}