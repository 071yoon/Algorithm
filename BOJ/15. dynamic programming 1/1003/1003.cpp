#include <stdio.h>

int main(){
    int cnt, num;
    int num_cnt[41] = {0, 1};
    
    for (int i = 2; i < 41; i++){
        num_cnt[i] = num_cnt[i - 1] + num_cnt[i - 2];
    }
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++){
        scanf("%d", &num);
        
        if (num == 0)
            printf("1 0\n");
        else
            printf("%d %d\n", num_cnt[num - 1], num_cnt[num]);
    }
}

//Fibo(N) = Fibo(N-1) + Fibo(N-2)

