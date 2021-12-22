#include <queue>
#include <iostream>
#include <string>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt;
    string order;

    cin >> cnt;
    queue <int> que;
    for (int i = 0; i < cnt; i++){
        cin >> order;
        int num;
        if (order == "push"){
            cin >> num;
            que.push(num);
        }
        else if (order == "front"){
            if (que.empty())
                cout << "-1\n";
            else
                cout << que.front() << "\n";
        }
        else if (order == "back"){
            if (que.empty())
                cout << "-1\n";
            else
                cout << que.back() << "\n";
        }
        else if (order == "size"){
            cout << que.size() << "\n";
        }
        else if (order == "empty"){
            if (que.empty())
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if (order == "pop"){
            if (que.empty())
                cout << "-1\n";
            else{
                cout << que.front() << "\n";
                que.pop();
            }
        }
    }
}