#include <iostream>
#include <set>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	long long x, cnt, num;
	while(cin >> x >> cnt){
		x *= 10000000;
		set <long long> s;
		for(int i = 0; i < cnt; i++){
			cin >> num;
			s.insert(num);
		}
		int flag = 1;
		while(!s.empty()){
			long long num = *s.begin();
			long long finder = x - num;
			s.erase(s.begin());
			if (s.count(finder)){
				cout << "yes " << num << " " << finder << "\n";
				flag = 0;
				break ;
			}
		}
		if (flag) cout << "danger\n";
	}
}