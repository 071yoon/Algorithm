#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
	if (prices.empty())
		return (0);
	int ret = 0;
	for(int i = 0; i < prices.size() - 1; i++){
		if (prices[i + 1] > prices[i])
			ret += prices[i + 1] - prices[i];
	}
	return (ret);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


}