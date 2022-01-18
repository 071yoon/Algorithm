#include <stack>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    string str;
    char cr;

    while (1){
        stack <int> small;
        string str;
        getline(cin, str);
        int flag = 1;
        int i = 0;
        if (str.size() == 1 && str[0] == '.')
            break;
        while (str[i] != '.'){
            if (str[i] == '('){
                small.push(str[i]);
            }
            else if (str[i] == '['){
             small.push(str[i]);
            }
            else if (str[i] == ')'){
                if (small.empty() || small.top() != '('){
                    flag = 0;
                    break;
                }
                else{
                    small.pop();
                }
            }
            else if (str[i] == ']'){
                if (small.empty() || small.top() != '['){
                    flag = 0;
                    break;
                }
                else{
                 small.pop();
                }
            }
            i++;
        }
        if (flag && small.empty())
            cout << "yes\n";
        else
            cout << "no\n";
    }
}