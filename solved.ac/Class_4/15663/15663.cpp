#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector <int> arr;
bool visited[8] = {0};
int print_arr[8];
void back_tracking(int cnt){
	if (cnt == M){//print
		for(int i = 0; i < M; i++){
			cout << print_arr[i] << " ";
		}
		cout << "\n";
		return ;
	}
	int previ = 0;
	for(int i = 0; i < N; i++){
		if (!visited[i] && previ != arr[i]){
			visited[i] = 1;
			print_arr[cnt] = arr[i];
			previ = arr[i];
			back_tracking(cnt + 1);
			visited[i] = 0;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	int num;
	for(int i = 0; i < N; i++){
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	back_tracking(0);
}