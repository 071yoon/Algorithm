#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(pair<double,int> a, pair<double, int> b){
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    double games[501][4] = {0};
    for(int i = 1; i <= N; i++){
        games[i][3] = i;
    }
    for(int i = 0; i < stages.size(); i++){
        for(int j = 1; j <= stages[i]; j++){
            games[j][1]++;
            if (j == stages[i]){
                games[j][2]++;
            }
        }
    }
	vector <pair<double, int> > for_sort;
    for(int i = 1; i <= N; i++){
        games[i][0] = games[i][2] / games[i][1];
		cout << games[i][0] << ":" << games[i][3] << "\n";
		for_sort.push_back(make_pair(games[i][0], games[i][3]));
    }
    stable_sort(for_sort.begin(), for_sort.end(), compare);
	cout << "\n" ;
    for(int i = 0; i < N; i++){
		cout << for_sort[i].second << "\n";
        answer.push_back(games[i][3]);
    }
    return answer;
}

int main(){
	int arr[8] = {2, 1, 2, 6, 2, 4, 3, 3};
	vector <int> vec(arr, arr + 8);
	solution(5, vec);
}
/*
1 2 3 4 5
game[501][3] -> {success, people, }
포함 + 넘을 때 마다 game[stage][1]++, 넘는사람에 한해서 game[stage][0]++
game[stage][2] = game[stage][0] / game[stage][1]
*/