#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	stack <char> stk;
	cin >> str;
	int ans = 0, tmp = 1;
	for(int i = 0; i < str.size(); i++){
		if (str[i] == '('){
			tmp *= 2;
			stk.push('(');
		}
		else if (str[i] == '['){
			tmp *= 3;
			stk.push('[');
		}
		else if (str[i] == ')'){
			if (stk.empty() || stk.top() != '('){
				ans = 0;
				break ;
			}
			else{
				if (str[i - 1] == '('){
					ans += tmp;
				}
				stk.pop();
				tmp /= 2;
			}
		}
		else if (str[i] == ']'){
			if (stk.empty() || stk.top() != '['){
				ans = 0;
				break ;
			}
			else{
				if (str[i - 1] == '['){
					ans += tmp;
				}
				stk.pop();
				tmp /= 3;
			}
		}
	}
	if (!stk.empty()) ans = 0;
	cout << ans << "\n";
}