#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set>
using namespace std;

bool visited[201] = {false};
string str;
stack <int> stk;
vector <pair<int, int> > vec;
set <string> s;

void dfs(int cnt, vector <int> cur) {
    if (cnt == vec.size()) {
        // do what i need to do
        for(int i = 0; i < cur.size(); i++) {
            cout << cur[i];
        }
        cout << "===\n";
        return ;
    }
    dfs(cnt + 1, cur);
    cur.push_back(cnt);
    dfs(cnt + 1, cur);
}

int main(){
    cin >> str;

    for(int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            stk.push(i);
        } else if (str[i] == ')') {
            int tmp = stk.top();
            stk.pop();
            vec.push_back(make_pair(tmp, i));
        }
    }

    vector <int> cur;
    dfs(0, cur);

}