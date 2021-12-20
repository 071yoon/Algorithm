#include <stdio.h>

int w[21][21][21] = {0};
int abc(int a, int b, int c){
    if (a <= 0 || b <= 0 || c <= 0){
        return (1);
    }
    else if (a > 20 || b > 20 || c > 20){
        return (abc(20, 20, 20));
    }
    else if (a < b && b < c){
        if (w[a][b][c] != 0) return w[a][b][c];
		else{
            w[a][b][c] = abc(a, b, c - 1) + abc(a, b - 1, c - 1) - abc(a, b - 1, c);
            return (w[a][b][c]);
        }
    }
    else{
        if (w[a][b][c] != 0) return w[a][b][c];
		else{
            w[a][b][c] = abc(a - 1, b, c) + abc(a - 1, b - 1, c) + abc(a - 1, b, c - 1) - abc(a - 1, b - 1, c - 1);
            return (w[a][b][c]);
        }
    }
}

int main(){
    int a, b, c;

    a = 1;
    while (1){
        scanf("%d %d %d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1)
            break;
        else
            printf("w(%d, %d, %d) = %d\n", a, b, c, abc(a, b, c));
    }
}