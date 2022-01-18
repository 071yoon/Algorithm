#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector <int> vec;
int print_arr[8] = {0};
void back_tracking(int cnt, int flag){
	if (cnt == M){
		for(int i = 0; i < M; i++){
			cout << print_arr[i] << " ";
		}
		cout << "\n";
		return ;
	}
	for(int i = flag; i < N; i++){
		print_arr[cnt] = vec[i];
		back_tracking(cnt + 1, i);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	int num;
	for(int i = 0; i < N; i++){
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	back_tracking(0, 0);
}