#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> dirs[17];
vector <int> info_cp;
int ans = 0;

void dfs(int wolf, int sheep, vector <int> next_nodes, int cur){
    if(info_cp[cur] == 0){
        sheep += 1;
    } else {
        wolf += 1;
    }
    if(wolf >= sheep){
        return;
    }
    ans = max(ans, sheep);
    for(int i = 0; i < next_nodes.size(); i++){
        int new_cur = next_nodes[i];
        vector <int> next = next_nodes;
        next.erase(next.begin() + i);
        for(int j = 0; j < dirs[new_cur].size(); j++){
            next.push_back(dirs[new_cur][j]);
        }
        dfs(wolf, sheep, next, new_cur);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    info_cp = info;
    for(int i = 0; i < edges.size(); i++){
        dirs[edges[i][0]].push_back(edges[i][1]);
    }
    vector <int> next_nodes;
    for(int i = 0; i < dirs[0].size(); i++){
        next_nodes.push_back(dirs[0][i]);
    }
    dfs(0, 0, next_nodes, 0);
    return ans;
}