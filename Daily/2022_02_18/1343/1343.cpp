#include <cstring>
#include <iostream>
using namespace std;

bool times4(string str, int index){
	for(int i = index; i < index + 4; i++){
		if (str[i] != 'X')
			return (false);
	}
	return (true);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	getline(cin, str);
	for(int i = 0; i < str.length(); i++){
		if (str[i] == '.')
			continue;
		if (str[i] == 'X'){
			if (i < str.length() - 3 && times4(str, i)){
				str[i] = 'A'; str[i + 1] = 'A'; str[i + 2] = 'A'; str[i + 3] = 'A';
				i += 3;
			}
			else if (i < str.length() - 1 && str[i + 1] == 'X'){
				str[i] = 'B'; str[i + 1] = 'B';
				i++;
			}
			else{
				cout << "-1\n";
				return (0);
			}
		}
	}
	cout << str << "\n";
}