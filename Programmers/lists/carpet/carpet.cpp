#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
	int sz = brown * yellow;
	for(int i = 3; i * i <= sz; i++){
		int test = sz / i;
		if ((sz % test == 0) && (test - 2) * (i - 2) == yellow){
			answer.push_back(i);
			answer.push_back(test);
		}
	}
    return answer;
}