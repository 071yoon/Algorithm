#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

string str;
vector <pair<int, int> > vec;
vector <deque<int> > deqs(4);
int cnt;

void init(){
	for(int i = 0; i < 4; i++){
		cin >> str;
		for(int j = 0; j < 8; j++){
			deqs[i].push_back(str[j] - '0');
		}
	}
}

void search_right(int me, int clock){
	if (me != 3 && deqs[me][2] != deqs[me + 1][6]){
		vec.push_back(make_pair(me + 1, clock * -1));
		search_right(me + 1, clock * -1);
	}
}

void search_left(int me, int clock){
	if (me != 0 && deqs[me][6] != deqs[me - 1][2]){
		vec.push_back(make_pair(me - 1, clock * -1));
		search_left(me - 1, clock * -1);
	}
}

void deal_vecs(){
	while(vec.size()){
		if (vec.front().second == 1){//clockwise
			int tmp = deqs[vec.front().first].back();
			deqs[vec.front().first].pop_back();
			deqs[vec.front().first].push_front(tmp);
		}
		else{//counter clockwise
			int tmp = deqs[vec.front().first].front();
			deqs[vec.front().first].pop_front();
			deqs[vec.front().first].push_back(tmp);
		}
		vec.erase(vec.begin());
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	init();
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		int me, clock;
		cin >> me >> clock;
		me--;
		vec.push_back(make_pair(me, clock));
		search_right(me, clock);
		search_left(me, clock);
		deal_vecs();
	}
	cout << deqs[0][0] * 1 + deqs[1][0] * 2 + deqs[2][0] * 4 + deqs[3][0] * 8 << "\n";
}