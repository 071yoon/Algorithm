#include <queue>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

vector <pair<int, int> > bus[10001];//destination, cost
int dst[10001] = {0};
bool visited[10001] = {0};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int cnt, buses, num1, num2, num3;
	cin >> cnt >> buses;
	for(int i = 1; i <= cnt; i++){
		dst[i] = 1e9;
	}
	for(int i = 0; i < buses; i++){
		cin >> num1 >> num2 >> num3;
		bus[num1].push_back(make_pair(num2, num3));
	}
	int chulbal, dochack;
	cin >> chulbal >> dochack;
	priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;//cost, dest
	dst[chulbal] = 0;
	que.push(make_pair(0, chulbal));
	while(!que.empty()){
		int nst = que.top().second;//new start
		int cost = que.top().first;
		que.pop();
		if (nst == dochack){
			cout << cost << "\n";
			return (0);
		}
		if (visited[nst])
			continue;
		visited[nst] = 1;
		for(int i = 0; i < bus[nst].size(); i++){
			if (dst[bus[nst][i].first] > cost + bus[nst][i].second){
				dst[bus[nst][i].first] = cost + bus[nst][i].second;
				que.push(make_pair(cost + bus[nst][i].second, bus[nst][i].first));
			}
		}
	}
	cout << dst[dochack] << "\n";
}