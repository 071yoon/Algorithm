#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(string new_id){
	string answer;

	for(int i = 0; i < new_id.size(); i++){
		if (new_id[i] >= 'A' && new_id[i] <= 'Z')
			new_id[i] = new_id[i] - 'A' + 'a';
	}
	for(int i = 0; i < new_id.size(); i++){
		if (!(new_id[i] == '.' || new_id[i] == '-' || new_id[i] == '_' ||
			(new_id[i] >= 'a' && new_id[i] <= 'z') || 
			(new_id[i] >= '0' && new_id[i] <= '9'))){
				int j;
				for(j = i; j < new_id.size() - 1; j++){
					new_id[j] = new_id[j + 1];
				}
				new_id[j] = '\0';
				i--;
		}
	}
	return new_id;
}
int main(){

	string answer;
	cin >> answer;
	cout << solution(answer) << "\n";
}