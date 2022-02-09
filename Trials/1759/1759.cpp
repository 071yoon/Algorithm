#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int L, C;
string org;

void back_tracking(int cnt, int moum, int jaum, int index, string str){
	if (cnt == L){
		if (moum >= 1 && jaum >= 2){
			cout << str << "\n";
		}
	}
	else{
		for(int i = index; i < org.size(); i++){
			str += org[i];
			if (org[i] == 'i' || org[i] == 'o' || org[i] == 'e' || org[i] == 'u' || org[i] == 'a')
				back_tracking(cnt + 1, moum + 1, jaum, i + 1, str);
			else
				back_tracking(cnt + 1, moum, jaum + 1, i + 1, str);
			str.pop_back();
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> L >> C;
	char cc;
	for(int i = 0; i < C; i++){
		cin >> cc;
		org += cc;
	}
	sort(org.begin(), org.end());
	back_tracking(0, 0, 0, 0, "");
}