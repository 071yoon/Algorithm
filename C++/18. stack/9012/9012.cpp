#include <stack>
#include <iostream>
#include <string>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int cnt, flag;
    string str;

    cin >> cnt;
    for (int i = 0; i < cnt; i++){
        flag = 1;
        cin >> str;
        stack <int> stack;
        for(int j = 0; j < str.size(); j++){
            if (str[j] == '(')
                stack.push(str[j]);
            else{
                if (!stack.empty())
                    stack.pop();
                else{
                    flag = 0;
                    break ;
                }
            }
        }
        if (stack.empty() && flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
