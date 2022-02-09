#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    unordered_map <string, int> kv;
	int arr[10001] = {0};
	int money[10001] = {0};
	for(int i = 0; i < enroll.size(); i++){
		kv[enroll[i]] = i + 1;
	}
//	arr[0] = -1;
	for(int i = 0; i < referral.size(); i++){
		if (referral[i] == "-"){
			arr[i + 1] = 0;
		}
		else{
			arr[i + 1] = kv[referral[i]];
		}
	}
	for(int i = 0; i < seller.size(); i++){
		int price = amount[i] * 100;
		int target = kv[seller[i]];
		while (target != 0){
			money[target] += price - (price / 10);
			target = arr[target];
			price = price / 10;
		}
	}
    vector<int> answer;
	for(int i = 0; i < enroll.size(); i++){
		answer.push_back(money[i + 1]);
	}
    return answer;
}