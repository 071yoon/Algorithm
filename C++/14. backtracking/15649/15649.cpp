#include <stdio.h>

int n,m;
int arr[8] = {0};
bool visited[9] = {0};

void dfs(int cnt){
    if(cnt == m){//when arrival
        for(int i = 0; i < m; i++)
            printf("%d ", arr[i]);//print saved value
        printf("\n");
        return;
    }
    for(int i = 1; i <= n; i++){//if not M
        if(!visited[i]){//if not visited
            visited[i] = true;//visited
            arr[cnt] = i;//count = visit
            dfs(cnt+1);//next value
            visited[i] = false;//backtracking
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    dfs(0);
}