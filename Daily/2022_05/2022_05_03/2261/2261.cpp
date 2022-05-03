#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int cnt, mini;
#define INF (1 << 30)

vector <pair<int, int> > points;
set <pair<int, int> > sets;

int dist(pair <int, int> &a, pair <int, int>& b){
	int xlen = (a.first - b.first) * (a.first - b.first);
	int ylen = (a.second - b.second) * (a.second - b.second);
	return xlen + ylen;
}

void inputs(){
	cin >> cnt;
	int x, y;
	for(int i = 0; i < cnt; i++){
		cin >> x >> y;
		points.push_back(make_pair(x, y));
	}
	sort(points.begin(), points.end());
	sets.insert(make_pair(points[0].second, points[0].first));
	sets.insert(make_pair(points[1].second, points[1].first));
	mini = dist(points[0], points[1]);
}

void solution(){
	int idx = 0;
	for(int i = 2; i < cnt; i++){
		while (idx < i) {
            int d = points[i].first - points[idx].first;
            if (d * d <= mini) break;
            else {
                sets.erase(make_pair(points[idx].second, points[idx].first));
                idx++;
            }
        }
        auto start = sets.lower_bound(make_pair(points[i].second - sqrt(mini), -INF));
        auto end = sets.lower_bound(make_pair(points[i].second + sqrt(mini), INF));
        for (auto it = start; it != end; it++){
			int tmp = (it->second - points[i].first) * (it->second - points[i].first) + (it->first - points[i].second) * (it->first - points[i].second);
			mini = min(mini, tmp);
		}
        sets.insert(make_pair(points[i].second, points[i].first));
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	inputs();
	solution();
	cout << mini << "\n";
}