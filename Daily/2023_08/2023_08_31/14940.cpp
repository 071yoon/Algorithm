#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int arr[1001][1001] = {0};
    int start_r, start_c;
    int r, c;
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                start_r = i;
                start_c = j;
            }
        }
    }
    while (1)
    {

    }
 }