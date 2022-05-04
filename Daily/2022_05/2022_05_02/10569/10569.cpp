#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int V, E, T;
	cin >> T;
	while(T--){
		cin >> V >> E;
		cout << 2 - V + E << "\n";
	}
}