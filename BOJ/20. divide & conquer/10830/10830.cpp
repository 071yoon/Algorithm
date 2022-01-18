#include <iostream>

using namespace std;
long long matrix[5][5];
long long ans[5][5] = {0};
long long ret[5][5];
int N, num;
long long B;

void matrix_mult(long long matrix1[5][5], long long matrix2[5][5]){
    long long ret[5][5];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            ret[i][j] = 0;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                ret[i][j] += matrix1[i][k] * matrix2[k][j];
            }
            ret[i][j] %= 1000;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            matrix1[i][j] = ret[i][j];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> B;
    for (int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cin >> matrix[i][j];
    }
    for(int i = 0; i < N; i++){
        ans[i][i] = 1;
    }
    while (B > 0){
        if (B % 2 == 1)
            matrix_mult(ans, matrix);
        B /= 2;
        matrix_mult(matrix, matrix);
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}