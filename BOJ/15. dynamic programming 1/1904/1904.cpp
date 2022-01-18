#include <stdio.h>

int main(){
    int num;
    long long ret[1000001] = {0};

    scanf("%d", &num);
    ret[0] = 0;
    ret[1] = 1;
    ret[2] = 2;
    for (int i = 3; i <= num; i++){
        ret[i] = (ret[i - 1] + ret[i - 2]) % 15746;
    }
    printf("%lld", ret[num]);
}