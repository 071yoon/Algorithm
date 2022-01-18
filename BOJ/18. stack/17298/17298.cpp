#include <stack>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int main(){
    int cnt;
    vector <int> v;
    vector <int> ans;

    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++){
        int num;
        scanf("%d", &num);
        v.push_back(num);
    }
    stack <int> stack;
    for (int i = cnt - 1; i >= 0; i--){
        while (!stack.empty() && stack.top() <= v[i])
			stack.pop();
		if (stack.empty()) 
            ans.push_back(-1);
		else
            ans.push_back(stack.top());
		stack.push(v[i]);
    }
    for (int i = cnt - 1; i >= 0; i--)
        printf("%d ", ans[i]);
}
