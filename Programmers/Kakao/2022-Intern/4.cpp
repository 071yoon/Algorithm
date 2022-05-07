#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;
int summit_no = 0;
int min_val = 2e9;

pair<int, int> val[50100]; //cost and summit
priority_queue<pi, vector<pi>, greater<pi> > graph[50100]; //cost and next
//vector<int, int> graph[50100]; //cost and next

void dfs(int summit, int node, int max_num, vector<int> &gates, vector<int> &summits){
    while(!graph[node].empty()){
        int cost = graph[node].top().first;
        cost = max(max_num, cost);
        int next = graph[node].top().second;
        graph[node].pop();
        // cout << next << " " << cost << " " << summit << "\n";
        if (val[next].first > cost){
            // cout << next << " " << cost << " " << summit << "\n";
            val[next].first = cost;
            val[next].second = summit;
            for(int i = 0; i < gates.size(); i++){
                if (next == gates[i]){
                    if (cost < min_val){
                        min_val = cost;
                        summit_no = summit;
                    }
                    return ;
                }
            }
            for(int i = 0; i < summits.size(); i++){
                if (next == summits[i]) return ;
            }
            cout << next << " " << cost << " " << summit << "\n";
            dfs(summit, next, cost, gates, summits);
        }
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    for(int i = 0; i <= n; i++){
        val[i] = make_pair(2e9, 0);
    }
    for(int i = 0; i < paths.size(); i++){
        graph[paths[i][0]].push(make_pair(paths[i][2], paths[i][1]));
        graph[paths[i][1]].push(make_pair(paths[i][2], paths[i][0]));
    }
    for(int i = 0; i < summits.size(); i++){
        dfs(summits[i], summits[i], 0, gates, summits);
    }
    vector<int> answer;
    answer.push_back(summit_no);
    answer.push_back(min_val);
    return answer;
}