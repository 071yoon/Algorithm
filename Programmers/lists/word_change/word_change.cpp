#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int one_change(string tmp, string word){
    int cnt = 0;
    for(int i = 0; i < tmp.size(); i++){
        if (tmp[i] != word[i])
            cnt++;
    }
    if (cnt == 1)
        return (1);
    else
        return (0);
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    bool visited[50] = {0};
    queue <pair<string, int> > que;
    que.push(make_pair(begin, 0));
    while (!que.empty()){
        string tmp = que.front().first;
        int cntr = que.front().second;
        que.pop();
        if (tmp == target){
            return cntr;
        }
        for(int i = 0; i < words.size(); i++){
            if (!visited[i] && one_change(tmp, words[i])){
                visited[i] = 1;
                que.push(make_pair(words[i], cntr + 1));
            }
        }
    }
    return answer;
}