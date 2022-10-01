#include <string>
#include <vector>

using namespace std;

long long solution(int k) {
  long long answer = -1;
  long long dp[52] = {0, };
  dp[0] = 0;
  dp[1] = 0;
  dp[2] = 1;
  dp[3] = 1;
  dp[4] = 2;
  dp[5] = 5;
  dp[6] = 7;
  dp[7] = 12;
  for(int i = 8; i <= 51; i++){
    for(int j = 0; j < 10; j++){
      if(i - 2 - 6 * j > 0) dp[i] += dp[i - 2 - 6 * j];
      if(i - 3 - 6 * j > 0) dp[i] += dp[i - 3 - 6 * j];
      if(i - 4 - 6 * j > 0) dp[i] += dp[i - 4 - 6 * j];
      if(i - 5 - 6 * j > 0) dp[i] += 3 * dp[i - 5 - 6 * j];
      if(i - 6 - 6 * j > 0) dp[i] += 2 * dp[i - 6 - 6 * j];
      if(i - 7 - 6 * j > 0) dp[i] += dp[i - 7 - 6 * j];
    }
  }
  answer = dp[k];
  return answer;
}