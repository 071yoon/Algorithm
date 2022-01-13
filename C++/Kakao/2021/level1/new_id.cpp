#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(string new_id){

	for(int i = 0; i < new_id.size(); i++){//1
		if (new_id[i] >= 'A' && new_id[i] <= 'Z')
			new_id[i] = new_id[i] - 'A' + 'a';
	}
	for(int i = 0; i < new_id.length(); i++){//2
		if (!(new_id[i] == '.' || new_id[i] == '-' || new_id[i] == '_' ||
			(new_id[i] >= 'a' && new_id[i] <= 'z') || 
			(new_id[i] >= '0' && new_id[i] <= '9'))){
			new_id.erase(new_id.begin() + i);
			i--;
		}
	}
	for(int i = 0; i < new_id.length(); i++){//3
		if (new_id[i] == '.'){
			while (new_id[i + 1] == '.'){
				new_id.erase(new_id.begin() + i + 1);
			}
		}
	}
	if (new_id.front() == '.')
		new_id.erase(new_id.begin());
	
	if (new_id.back() == '.')
		new_id.erase(new_id.end() - 1);
	
	if (new_id.length() == 0){//5
		new_id = 'a';
	}
	if (new_id.length() >= 16){//6
		while(new_id.length() != 15){
            new_id.erase(new_id.begin() + 15);
        }
	}
	if (new_id.back() == '.')
		new_id.erase(new_id.end() - 1);
	
    if (new_id.length() <= 2){
        while(new_id.length() != 3){
            new_id += new_id.back();
        }
    }

	return new_id;
}
int main(){

	string answer;
	cin >> answer;
	cout << solution(answer) << "\n";
}