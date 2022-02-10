#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
bool visited[10001] = {0};
int flag = 1;
void dfs(string str, int cnt, int sz, vector<vector<string>> &tickets){
	answer.push_back(str);
	if (cnt == sz){
        flag = 0;
		return ;
	}
	else{
		for(int i = 0; i < tickets.size(); i++){
			if (str == tickets[i][0] && !visited[i]){
				visited[i] = 1;
				dfs(tickets[i][1], cnt + 1, sz, tickets);
                if (flag == 0)
                    return ;
				visited[i] = 0;
			}
		}
	}
	answer.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
	sort(tickets.begin(), tickets.end());
	dfs("ICN", 0, tickets.size(), tickets);

    return answer;
}