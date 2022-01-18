#include <stack>
#include <iostream>
#include <vector>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt;
    cin >> cnt;
    vector <int> org;
    stack <int> stack;
    vector <string> ret;
    int num;
    for (int i = 0; i < cnt; i++){
        cin >> num;
        org.push_back(num);
    }
    int k = 0;
    for (int i = 1; i < cnt + 1; i++){
        stack.push(i);
        ret.push_back("+");
        while (!stack.empty() && (stack.top() == org[k])){
            stack.pop();
            ret.push_back("-");
            k++;
        }
    }
    if (k == cnt && stack.empty())
        for(int i = 0; i < ret.size(); i++)
            cout << ret[i] << "\n";
    else
        cout << "NO\n";
}