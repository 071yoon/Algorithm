#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int cnt, num, sum;

    vector <int> v;
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++){
        scanf("%d", &num);
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    sum = v[0];
    for (int i = 1; i < cnt; i++){
        v[i] += v[i - 1];
        sum += v[i];
    }
    printf("%d", sum);
}