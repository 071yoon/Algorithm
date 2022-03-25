#include <iostream>
using namespace std;

int num;
int num_arr[8] = {0};
bool visited[8] = {0};

void back_tracking(int cnt){
	if (cnt == num){
		for(int i = 0; i < num; i++){
			cout << num_arr[i] + 1 << " ";
		}
		cout << "\n";
		return ;
	}
	for(int i = 0; i < num; i++){
		if (!visited[i]){
			num_arr[cnt] = i;
			visited[i] = 1;
			back_tracking(cnt + 1);
			visited[i] = false;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> num;
	back_tracking(0);
}