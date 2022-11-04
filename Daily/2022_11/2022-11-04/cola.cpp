#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while(n){
      int left = n % a;
      int give = (n / a) * b;
      answer += give;
      n = left + give;
      if (n < a) break;
    }
    return answer;
}