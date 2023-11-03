#include <iostream>
#include <string>
using namespace std;

bool visited[51] = { false };
int sz;
bool flag = false;
string str;

void dfs(int cnt, string tmp, string ans) {
    if (cnt == str.size()) {
        if (!flag) {
            flag = true;
            cout << ans << "\n";
        }
        return;
    }
    for(int i = cnt; i < str.size(); i++) {
        tmp += str[i];
        if (tmp.size() >= 3) return;
        int num_tmp = stoi(tmp);
        if (1 <= num_tmp && num_tmp <= sz && !visited[num_tmp]) {
            visited[num_tmp] = true;
            dfs(i + 1, "", ans + tmp + " ");
            visited[num_tmp] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> str;
    sz = str.size() > 9 ? 9 + (str.size() - 9) / 2 : str.size();
    string tmp = "";
    string ans = "";
    dfs(0, tmp, ans);
}