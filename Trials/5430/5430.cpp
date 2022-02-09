#include <deque>
#include <stack>
#include <iostream>
#include <string>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt;
    cin >> cnt;
    for (int loop = 0; loop < cnt; loop++){
        string str;
        int num;
        int flag = 1;
        int rev_flag = 1;
        string str_que;
        deque <int> que;
        cin >> str;
        cin >> num;
        cin >> str_que;
        int k = 1;
        for (int i = 0; i < num; i++){
            int get_num = 0;
            if (str_que[k] == ',')
                k++;
            while (str_que[k] != ',' && str_que[k] != ']'){
                get_num = get_num * 10 + str_que[k] - '0';
                k++;
            }
            que.push_back(get_num);
        }
        for(int i = 0; i < str.size(); i++){
            if (str[i] == 'R'){
                rev_flag *= -1;
            }
            else if (str[i] == 'D'){
                if (que.empty()){
                    flag = 0;
                    break;
                }
                else if (rev_flag == -1){
                    que.pop_back();
                }
                else
                    que.pop_front();
            }
        }
        if (flag == 1 && rev_flag == 1){
            cout << "[";
            while (!que.empty()){
                cout << que.front();
                que.pop_front();
                if (!que.empty())
                    cout << ",";
            }
            cout << "]";
        }
        else if (flag == 1 && rev_flag == -1){
            cout << "[";
            while (!que.empty()){
                cout << que.back();
                que.pop_back();
                if (!que.empty())
                    cout << ",";
            }
            cout << "]";
        }
        else{
            cout << "error";
        }
        cout << "\n";
    }
}