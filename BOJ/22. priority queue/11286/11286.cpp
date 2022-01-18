#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	priority_queue <int, vector<int>, greater<int> > plusy;
	priority_queue <int> minusy;
	int N, num;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (num == 0){
			if (plusy.empty() && minusy.empty()){
				cout << "0\n";
			}
			else{
				if (plusy.empty() && !(minusy.empty())){
					cout << minusy.top() << "\n";
					minusy.pop();
				}
				else if (!(plusy.empty()) && minusy.empty()){
					cout << plusy.top() << "\n";
					plusy.pop();
				}
				else if (abs(plusy.top()) < abs(minusy.top())){
					cout << plusy.top() << "\n";
					plusy.pop();
				}
				else if (abs(plusy.top()) >= abs(minusy.top())){
					cout << minusy.top() << "\n";
					minusy.pop();
				}
			}
		}
		else{
			if (num >= 0){
				plusy.push(num);
			}
			else{
				minusy.push(num);
			}
		}
	}
	

}