#include <string>
#include <vector>

using namespace std;

int solution(int width, int height, vector<vector<int>> diagonals) {
    long long dp[251][251] = {0};
    for(int i = 0; i <= width; i++){
        for(int j = 0; j <= height; j++){
            dp[i][j] = 1;
            if (j > 0 && i > 0)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= 10000019;
        }
    }
    int answer = 0;
    for(int i = 0; i < diagonals.size(); i++){
        int x = diagonals[i][0];
        int y = diagonals[i][1];
        long long fb = (dp[x - 1][y] * dp[width - x][height - y + 1]) % 10000019;
        long long sb = (dp[x][y - 1] * dp[width - x + 1][height - y]) % 10000019;
        answer = (answer + fb + sb) % 10000019;
    }
    return answer;
}