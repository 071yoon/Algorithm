#include <stdio.h>

int main(){
    int cnt, num;
    long long ret[101] = {0};

    scanf("%d", &cnt);
    ret[0] = 1;
    ret[1] = 1;
    ret[2] = 1;
    for (int i = 0; i < cnt; i++){
        scanf("%d", &num);
        for(int k = 3; k < num; k++){
            ret[k] = ret[k - 2] + ret[k - 3];
        }
        printf("%lld\n", ret[num - 1]);
    }
}