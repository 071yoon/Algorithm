#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt;
	cin >> cnt;
	for (int loop = 0; loop < cnt; loop++){
		vector <pair<string, int> > vec;
		int num;
		cin >> num;
		for(int loop2 = 0; loop2 < num; loop2++){
			string a, b;
			int flag = -1;
			cin >> a >> b;
			for(int i = 0; i < vec.size(); i++){
				if (vec[i].first == b){
					flag = i;
					break ;
				}
			}
			if (flag == -1){
				vec.push_back(make_pair(b, 1));
				cout << "added pair\n";
			}
			else{
				vec[flag].second++;
				cout << "added flag\n";
			}
		}
		int ret = 1;
		for (int i = 0; i < vec.size(); i++){
			ret *= vec[i].second + 1;
		}
		cout << ret - 1 << "\n";
	}
}