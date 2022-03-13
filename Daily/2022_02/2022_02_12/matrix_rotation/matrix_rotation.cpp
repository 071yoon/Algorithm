#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int graph[101][101];
vector <int> answer;

void rotater(int y1, int x1, int y2, int x2){
    int tmp = graph[y1][x1];
    int mini = graph[y1][x1];
    for(int i = y1 + 1; i <= y2; i++){
        graph[i - 1][x1] = graph[i][x1];
        mini = min(mini, graph[i][x1]);
    }
    for(int i = x1 + 1; i <= x2; i++){
        graph[y2][i - 1] = graph[y2][i]; 
        mini = min(mini, graph[y2][i]);
    }
    for(int i = y2 - 1; i >= y1; i--){
        graph[i + 1][x2] = graph[i][x2]; 
        mini = min(mini, graph[i][x2]);
    }
    for(int i = x2 - 1; i >= x1; i--){
        graph[y1][i + 1] = graph[y1][i];
        mini = min(mini, graph[y1][i]);
    }
    graph[y1][x1 + 1] = tmp;
    answer.push_back(tmp);
}

vector<int> solution(int rows, int columns, vector<vector<int> > queries) {
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            graph[i][j] = (i - 1) * columns + j;
        }
    }
    
    for(int i = 0; i < queries.size(); i++){
        rotater(queries[i][0], queries[i][1], queries[i][2], queries[i][3]);
    }
    return answer;
}

int main(){
	vector <int> a;
	a.push_back(2);
	a.push_back(2);
	a.push_back(5);
	a.push_back(4);
	vector <int> b;
	b.push_back(3);
	b.push_back(3);
	b.push_back(6);
	b.push_back(6);
	vector <int> c;
	c.push_back(5);
	c.push_back(1);
	c.push_back(6);
	c.push_back(3);
	vector<vector<int> > vec;
	vec.push_back(a);
	vec.push_back(b);
	vec.push_back(c);
	solution(6, 6, vec);
	for(int i = 1; i <= 6; i++){
		for(int j = 1; j <= 6; j++){
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
}
/*
[y1,  x1] [y1,x1+1] [y1,x1+2] ~ [y1,  x2]
[y1+1,x1]          ~            [y1+1,x2]
    ~
[y2,  x1]          ~            [y2,  x2]
*/