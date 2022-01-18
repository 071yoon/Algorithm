#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main(){
    int cnt;
    stack <int> stack;
    string order;
    cin.tie(NULL);

    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++){
        cin >> order;

        if (order == "push"){
            int num;
            scanf("%d", &num);
            stack.push(num);
        }
        else if (order == "pop"){
            if (!stack.empty()){
                printf("%d\n", stack.top());
                stack.pop();
            }
            else
                cout << "-1" << "\n";
        }
        else if (order == "size")
            printf("%d\n", stack.size());
        else if (order == "empty"){
            if (!stack.empty())
                printf("0\n");
            else
                printf("1\n");
        }
        else if (order == "top"){
            if (!stack.empty())
                printf("%d\n", stack.top());
            else
                printf("-1\n");
        }  
    }
    return (0);
}