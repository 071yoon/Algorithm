#include <iostream>
#include <algorithm>
using namespace std;

bool adj[32][12] = {0};
int sero, garo_cnt, garo;

int test_graph(int num1, int num2){
	if (num1 == (garo + 1)){//END
		return num2;
	}
	if (adj[num1][num2]){
		return test_graph(num1 + 1, num2 + 1);
	}
	else if (adj[num1][num2 - 1]){
		return test_graph(num1 + 1, num2 - 1);
	}
	else{
		return test_graph(num1 + 1, num2);
	}
}

int main_test(){
	for(int i = 1; i <= sero; i++){
		if (i != test_graph(1, i)){
			return (0);
		}
	}
	return (1);
}

int run_test(int cnt, int index, int cnter){
	if (cnt == cnter){
		if (main_test()){
			return (1);
		}
	}
	else{
		for(int i = index; i <= garo * (sero - 1); i++){//one added
			int new_i = (i - 1) / (sero - 1) + 1;
			int new_j = (i - 1) % (sero - 1) + 1;
			if (adj[new_i][new_j] == 0 && adj[new_i][new_j - 1] == 0 && adj[new_i][new_j + 1] == 0){
				adj[new_i][new_j] = 1;
				if(run_test(cnt + 1, i + 1, cnter))
					return (1);
				adj[new_i][new_j] = 0;
			}
		}
	}
	return (0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> sero >> garo_cnt >> garo;
	for(int i = 0; i < garo_cnt; i++){
		int a, b;
		cin >> a >> b;
		adj[a][b] = 1;
	}
	for(int i = 0; i <= 3; i++){
		if (run_test(0, 1, i)){
			cout << i << "\n";
			return (0);
		}
	}
	cout << "-1\n";
	return (0);
}