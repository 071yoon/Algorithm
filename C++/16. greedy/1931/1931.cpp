#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int main(){
	int cnt, num1, num2;

	vector <pair<int, int> > v;
	
	scanf("%d", &cnt);
	for(int i = 0; i < cnt; i++){
		scanf("%d %d", &num1, &num2);
		v.push_back(make_pair(num2, num1));
	}

	sort(v.begin(), v.end());
	int starter = v[0].first;
	int counter = 1;

	for (int i = 1; i < cnt; i++){
		if (starter <= v[i].second){
			counter++;
			starter = v[i].first;
		}
	}

	printf("%d", counter);
	return (0);
}