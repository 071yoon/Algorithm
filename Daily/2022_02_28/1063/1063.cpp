#include <string>
#include <iostream>
using namespace std;

int directions[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, 1}, {-1, -1}, {1, 1}, {1, -1}};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str1, str2;
	int cnt;
	cin >> str1 >> str2 >> cnt;
	int kx, ky, rx, ry; //king x, y rock x, y
	kx = '8' - str1[1];//8 -> 0, 7 -> 1, 6 -> 2, 1 -> 7
	ky = str1[0] - 'A';
	rx = '8' - str2[1];
	ry = str2[0] - 'A';
	for(int i = 0; i < cnt; i++){
		string tmp; int d;
		cin >> tmp;
		int nkx, nky, nrx, nry;
		if (tmp == "R"){
			d = 0;
		}
		else if (tmp == "L"){
			d = 1;
		}
		else if (tmp == "B"){
			d = 2;
		}
		else if (tmp == "T"){
			d = 3;
		}
		else if (tmp == "RT"){
			d = 4;
		}
		else if (tmp == "LT"){
			d = 5;
		}
		else if (tmp == "RB"){
			d = 6;
		}
		else{
			d = 7;
		}
		nkx = kx + directions[d][0];
		nky = ky + directions[d][1];
		if (nkx >= 0 && nkx < 8 && nky >= 0 && nky < 8){
			if (nkx == rx && nky == ry){
				nrx = rx + directions[d][0];
				nry = ry + directions[d][1];
				if (nrx >= 0 && nrx < 8 && nry >= 0 && nry < 8){
					kx = nkx; ky = nky; rx = nrx; ry = nry;
				}
				else{
					continue;
				}
			}
			else{
				kx = nkx; ky = nky;
			}
		}
		else{
			continue;
		}
	}
	//0 -> 8, 1 -> 7
	cout << (char)(ky + 'A') << (char)('8' - kx) << "\n";
	cout << (char)(ry + 'A') << (char)('8' - rx) << "\n";
}
//34 mins 50sec