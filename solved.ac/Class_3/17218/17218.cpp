#include <iostream>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string pass1, pass2;
	cin >> pass1 >> pass2;
	int tmp = 0;
	for(int i = 0; i < pass1.length(); i++){
		for(int j = tmp; j < pass2.length(); j++){
			if (pass1[i] == pass2[j]){
				cout << pass2[i]
			
			}
		}
	}
}