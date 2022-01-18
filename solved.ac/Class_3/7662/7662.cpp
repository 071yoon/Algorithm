#include <iostream>
#include <set>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt, num, target;
	char c;
	cin >> cnt;
	for(int i = 0; i < cnt; i++){
		cin >> num;
		multiset <int> set;
		for(int k = 0; k < num; k++){
			cin >> c >> target;
			if (c == 'I'){
				set.insert(target);
			}
			else{
				if (target == 1){
					if (set.empty())
						continue;
					auto iter = set.end();
					set.erase(--iter);
				}
				else{
					if (set.empty())
						continue;
					set.erase(set.begin());
				}
			}
		}
		if (set.empty())
			cout << "EMPTY\n";
		else{
			auto iter = set.end();
			cout << *(--iter) << " " << *(set.begin()) << "\n";
		}
	}

}