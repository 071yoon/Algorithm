#include <string>
#include <vector>
#include <iostream>
using namespace std;
int nums[10] = {0};
int answer = 0;

int isprime(int num){
	if (num < 2)
		return (0);
	for(int i = 2; i * i <= num; i++){
		if (num % i == 0){
			return (0);
		}
	}
	return (1);
}

void back_tracking(int num){
	if (isprime(num))
		answer++;
	for(int i = 0; i <= 9; i++){
		if (nums[i]){
			nums[i]--;
			back_tracking(num * 10 + i);
			nums[i]++;
		}
	}
}

int solution(string numbers) {

	for(int i = 0; i < numbers.length(); i++){
		nums[numbers[i] - '0'] += 1;
//		cout << numbers[i]  << "\n";
	}
	
	for(int i = 1; i <= 9; i++){
		if (nums[i] > 0){
			nums[i]--;
			back_tracking(i);
			nums[i]++;
		}
	}
    return answer;
}

int main(){
	cout << solution("011");
}