#include <stdio.h>
#include <algorithm>

int main(){
    int tree[501][501] = {0};
    int tree_cnt, num;

    scanf("%d", &tree_cnt);
    for (int i = 0; i < tree_cnt; i++){
        for(int k = 0; k < i + 1; k++){
            scanf("%d", &num);
            tree[i][k] = num;
        }
    }
    for (int i = 1; i < tree_cnt; i++){
        for (int k = 0; k < i + 1; k++){
            if ((k - 1) < 0){
                tree[i][k] = tree[i - 1][k] + tree[i][k];
            }
            else
                tree[i][k] = std::max(tree[i - 1][k - 1] + tree[i][k], tree[i - 1][k] + tree[i][k]);
        }
    }
    std::sort(tree[tree_cnt - 1], tree[tree_cnt - 1] + 501);
    printf("%d", tree[tree_cnt - 1][500]);
}