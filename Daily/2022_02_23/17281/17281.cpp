#include <iostream>
using namespace std;

int main(){
	double min_val = 1123456789;
	double max_val = 0;
	double N, L, W, H;
	cin >> N >> L >> W >> H;
	max_val = min(min_val, min(L, min(W, H)));
	min_val = 0;
	double ret = 0;
	cout << fixed;
	cout.precision(10);
	for(int i = 0; i < 1000; i++){
//		cout << max_val << " " << min_val << "\n";
		double mid = (max_val + min_val) / 2;
		double num = (long long)(L / mid) * (long long)(W / mid) * (long long)(H / mid);
//		cout << num << "\n";
		if (num >= N){
			ret = mid;
			min_val = mid;
		}
		else{
			max_val = mid;
		}
	}
	cout << ret << "\n";
}