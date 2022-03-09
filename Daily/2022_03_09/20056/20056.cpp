#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int directions[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
int sz, cnt, times;
struct fireball{
	int mass = 0;
	int dir = 0;
	int spd = 0;
};
vector <fireball> mapp[51][51];

void spend(){
	vector <fireball> tmp[51][51];
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++){
			for(int k = 0; k < mapp[i][j].size(); k++){
				int ni = i + directions[mapp[i][j][k].dir][0] * mapp[i][j][k].spd;
				int nj = j + directions[mapp[i][j][k].dir][1] * mapp[i][j][k].spd;
				if (ni >= sz) ni %= sz;
				if (nj >= sz) nj %= sz;
				if (ni < 0) ni = (sz - (abs(ni) % sz)) % sz;
				if (nj < 0) nj = (sz - (abs(nj) % sz)) % sz;
				tmp[ni][nj].push_back(mapp[i][j][k]);
			}
		}
	}
	memset(mapp, 0, sizeof(mapp));
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++){
			if (tmp[i][j].size() == 1){
				mapp[i][j].push_back(tmp[i][j][0]);
			}
			else if (tmp[i][j].size() > 1){
				int flag = 0;
				int k = tmp[i][j][0].dir % 2;
				int new_mass = 0, new_spd = 0;
				for(int r = 0; r < tmp[i][j].size(); r++){
					if (k != tmp[i][j][r].dir % 2) flag = 1;
					new_mass += tmp[i][j][r].mass;
					new_spd += tmp[i][j][r].spd;
				}
				new_mass /= 5;
				new_spd /= tmp[i][j].size();
				if (new_mass == 0) continue ;
				for(int r = flag; r < 8; r += 2){
					fireball f; f.mass = new_mass; f.dir = r; f.spd = new_spd;
					mapp[i][j].push_back(f);
				}
			}
		}
	}
}

int main(){
	cin >> sz >> cnt >> times;
	for(int i = 0; i < cnt; i++){
		int x, y, m, d, s;
		cin >> x >> y >> m >> s >> d;
		fireball f; f.mass = m; f.dir = d; f.spd = s;
		mapp[x - 1][y - 1].push_back(f);
	}
	for(int i = 0; i < times; i++){
		spend();
	}
	int ret = 0;
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < sz; j++){
			for(int k = 0; k < mapp[i][j].size(); k++){
				ret += mapp[i][j][k].mass;
			}
		}
	}
	cout << ret << "\n";
}
