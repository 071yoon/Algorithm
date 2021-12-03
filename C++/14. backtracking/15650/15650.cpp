#include <stdio.h>

int n,m,tmp;
int arr[8] = {0};
bool visited[9] = {0};

void dfs(int cnt){
    if(cnt == m){//when arrival
        for(int i = 0; i < m; i++){
            printf("%d ", arr[i]);//print saved value
        }
        printf("\n");
        return;
    }
    for(int i = 1; i <= n; i++){//if not M
        if(!visited[i]){//if not visited
            visited[i] = true;//visited
			tmp = arr[cnt];
			arr[cnt] = i;
			if (arr[cnt - 1] < arr[cnt]){
            	arr[cnt] = i;//count = visit
            	dfs(cnt+1);//next value
			}
			else
				arr[cnt] = tmp;
            visited[i] = false;//backtracking
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    dfs(0);
}