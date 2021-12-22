#include <iostream>
#include <queue>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue <int> cards;
    int cnt;
    cin >> cnt;
    for (int i = 1; i < cnt + 1; i++){
        cards.push(i);
    }
    while (cards.size() > 1){
        cards.pop();
        cards.push(cards.front());
        cards.pop();
    }
    cout << cards.front();
}