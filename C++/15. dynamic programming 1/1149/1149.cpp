#include <stdio.h>
#include <algorithm>

int main(){
    int cnt, r, g, b;
    int old_r, old_g, old_b;
    int new_r, new_g, new_b;

    scanf("%d", &cnt);
    scanf("%d %d %d", &old_r, &old_g, &old_b);
    for (int i = 0; i < cnt - 1; i++){
        new_r = old_r;
        new_g = old_g;
        new_b = old_b;
        scanf("%d %d %d", &r, &g, &b);
        old_r = std::min(new_g, new_b) + r;
        old_g = std::min(new_r, new_b) + g;
        old_b = std::min(new_g, new_r) + b;
    }
    int ret = std::min(std::min(old_r, old_g), old_b);
    printf("%d", ret);
}