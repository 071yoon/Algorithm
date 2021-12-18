#include <stdio.h>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}

int main(){
	int cnt, start, end;

	vector <pair<int, int> > v;
	scanf("%d", &cnt);
	for(int i = 0; i < cnt; i++){
		scanf("%d %d", &start, &end);
		v.push_back(make_pair(end, start));
	}

	sort(v.begin(), v.end(), compare);
	int strt = v[0].first;
	int count = 1;
	for (int i = 1; i < cnt; i++){
		if (strt <= v[i].second){
			count++;
			strt = v[i].first;
		}
	}
	printf("%d", count);
}