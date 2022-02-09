#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, S, M;
	cin >> N >> S >> M;
	set <int> a;
	set <int> b;
	vector <int> guitar;
	for(int i = 0; i < N; i++){
		int num;
		cin >> num;
		guitar.push_back(num);
	}
	a.insert(S);
	int flag = 1;
	for(int i = 0; i < N; i++){
		if (i % 2 == 0){
			if (a.size() == 0){
				flag = 0;
				break ;
			}
			int sz = a.size();
			for(int j = 0; j < sz; j++){
				int num = *a.begin();
				a.erase(a.begin());
				if (num - guitar[i] >= 0){
					b.insert(num - guitar[i]);
				}
				if (num + guitar[i] <= M){
					b.insert(num + guitar[i]);
				}
			}
		}
		else{
			if (b.size() == 0){
				flag = 0;
				break ;
			}
			int sz = b.size();
			for(int j = 0; j < sz; j++){
				int num = *b.begin();
				b.erase(b.begin());
				if (num - guitar[i] >= 0){
					a.insert(num - guitar[i]);
				}
				if (num + guitar[i] <= M){
					a.insert(num + guitar[i]);
				}
			}
		}
	}
	if (flag){
		if (N % 2 == 0 && a.size()){
			cout << *--a.end() << "\n";
		}
		else if (N % 2 == 1 && b.size()){
			cout << *--b.end() << "\n";
		}
		else{
			cout << "-1\n";
		}
	}
	else
		cout << "-1\n";
}