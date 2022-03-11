#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int cnt, cnt2;
    string tmp;
	int ans = 0;
    vector <string> words;
    cin >> cnt >> cnt2;
    for(int i = 0; i < cnt; i++){
        cin >> tmp;
        words.push_back(tmp);
    }
    for(int i = 0; i < cnt2; i++){
        cin >> tmp;
        for(int j = 0; j < (int)words.size(); j++){
			if (words[j].size() < tmp.size()){
				continue ;
			}
            int flag = 1;
            int k = 0;
            while(k != words[j].size() && k != tmp.size()){
                if (words[j][k] == tmp[k]){
                    k++;
                    continue;
                }
                else{
                    flag = 0;
                    break;
                }
            }
            if (flag){
                ans++;
				break ;
            }
        }
    }
	cout << ans << "\n";
    return 0;
}