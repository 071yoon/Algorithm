#include <iostream>
#include <vector>

using namespace std;


long long Fi(long long num){

   if(num == 1)
      return 1;
   else if( num ==2 )
      return 1;
   else
      return Fi(num-1)+Fi(num-2);
} 

int main() {
   long long num;
   long long dp[100];
	dp[1] = 1;
	dp[2] = 1;
   cin >>num;

	for(int i = 3; i <= num; i++){
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[num] << "\n";
 //  cout<< Fi(num)<<endl;
   return 0;
}
/*
제가 5번째
3번째 + 4번째
3번째 = 1번째 + 2번째
4번째 = 2번째 + 3번째

*/