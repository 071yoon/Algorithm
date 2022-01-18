#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int repeat, len, ans = 0;
	string org;
	cin >> repeat;
	cin >> len;
	cin >> org;
	 for(int i = 1; i < org.size(); i++){
        int count = 0;
        if(org[i - 1] == 'I'){
            while(org[i] == 'O' && org[i + 1] == 'I'){
                i += 2;
                count++;
                if(count >= repeat)
					ans++;
            }
        }
    }
    cout << ans <<'\n';
}