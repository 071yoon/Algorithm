#include <stdio.h>

int main(){
    int city[100000];
    int price[100001];
    int cnt;
    long long ret;

    scanf("%d", &cnt);
    for (int i = 0; i < cnt - 1; i++){
        scanf("%d", &city[i]);
    }
    for (int i = 0; i < cnt; i++){
        scanf("%d", &price[i]);
    }
    ret = 0;
    int max = __INT_MAX__;
    for (int i = 0; i < cnt - 1; i++){
        if (max > price[i]){
            max = price[i];
        }
        ret += (long long)max * city[i];
    }
    printf("%lld", ret);
}
