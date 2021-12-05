
/*
My Code
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
    if (cnt == 0){
        for(int i = 1; i <= n; i++){//if not M
            if(!visited[i]){//if not visited
                if (i == n && cnt == m)
                    visited[i] = true;//visited
                arr[cnt] = i;
                dfs(cnt + 1);//next value
                visited[i] = false;//backtracking
            }
        }
    }
    else{
        for(int i = arr[cnt - 1]; i <= n; i++){//if not M
            if(!visited[i]){//if not visited
                if (i == n && cnt == m)
                    visited[i] = true;//visited
                arr[cnt] = i;
                dfs(cnt + 1);//next value
                visited[i] = false;//backtracking
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    dfs(0);
}

*/


//Version 2

#include <stdio.h>
#include <string>

using namespace std;

int N, M;

void dfs(char *prefix, int last_num, int length) {
    if (length == M) {
       for (int i = last_num; i <= N; i++) {
            if (i == 0) continue;
            printf("%s %d\n", prefix, i);
        } 
    } else {
        for (int i = last_num; i <= N; i++) {
            if (i == 0) continue;
            dfs(prefix + to_string(i) + " ", i, length + 1);
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    
    dfs("dddj", 0, 1);
}


