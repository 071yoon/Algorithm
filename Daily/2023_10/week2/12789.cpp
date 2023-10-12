#include <iostream>
#include <stack>
#include <queue>
using namespace std;

queue <int> que;
stack <int> stk;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int cnt, num;
    cin >> cnt;
    for(int i = 0; i < cnt; i++) {
        cin >> num;
        que.push(num);
    }
    int cur = 1;
    while(!que.empty()) {
        if (que.front() == cur) {
            que.pop();
            cur++;
            continue;
        } else if (!stk.empty() && stk.top() == cur) {
            stk.pop();
            cur++;
            continue;
        }

        int tmp = que.front();
        que.pop();
        stk.push(tmp);
    }
    // deq is empty
    while(!stk.empty()){
        if (stk.top() == cur) {
            stk.pop();
            cur++;
        } else {
            cout << "Sad\n";
            return 0;
        }
    }
    cout << "Nice\n";
}   