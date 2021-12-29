#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	priority_queue <unsigned long long, vector<unsigned long long>, greater<unsigned long long> > que;

	int N;
	unsigned long long num;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (num == 0){
			if (que.empty()){
				cout << "0\n";
			}
			else{
				cout << que.top() << "\n";
				que.pop();
			}
		}
		else{
			que.push(num);
		}
	}
	
}