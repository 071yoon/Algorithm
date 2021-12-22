#include <stack>
#include <iostream>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    stack <int> stack;
    int cnt;

    cin >> cnt;
    for(int i = 0; i < cnt; i++){
        int num;
        cin >> num;
        if (num != 0)
            stack.push(num);
        else
            stack.pop();
    }
    int ret = 0;
    cnt = stack.size();
    for(int i = 0; i < cnt; i++){
        ret += stack.top();
        stack.pop();
    }
    cout << ret;
}
