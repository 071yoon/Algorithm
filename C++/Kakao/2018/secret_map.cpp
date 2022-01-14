#include <iostream>
#include <string>
#include <vector>
using namespace std;

string convert(int n, int num){
	string str_ret;
	vector <char> ret(n);
	int tmp = n;
	while(--n != -1){
		if (num % 2){
			ret[n] = '1';
		}
		else
			ret[n] = '0';
		num /= 2;
	}
	for(int i = 0; i < tmp; i++)
		str_ret.push_back(ret[i]);
//	cout << str_ret << "\n";
	return (str_ret);
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> tmp(n);
	for(int i = 0; i < n; i++){
		tmp[i] = convert(n, arr1[i]);
	}
	for(int i = 0; i < n; i++){
		string tmp_now = convert(n, arr2[i]);
		for(int j = 0; j < n; j++){
			if (tmp[i][j] == '1' || tmp_now[j] == '1')
				tmp[i][j] = '#';
			else{
				tmp[i][j] = ' ';
			}	
		}
	}

    return tmp;
}

int main(){
	int n;
	cin >> n;
	vector <int> arr1(n);
	vector <int> arr2(n);
	vector <string> ans(n);
	for(int i = 0; i < n; i++){
		cin >> arr1[i];
	}
	for(int i = 0; i < n; i++){
		cin >> arr2[i];
	}
	ans = solution(n, arr1, arr2);
	for(int i = 0; i < n; i++)
		cout << ans[i] << "\n";
}
/*
for(int i = 0; i < n; i++)
    {
        string tmp = "";
        arr1[i] = arr1[i] | arr2[i];
        
        while(tmp.size() != n)
        {
            if(arr1[i] % 2 == 0)
                tmp.push_back(' ');
            else
                tmp.push_back('#');
            arr1[i] /= 2;
        }
        
        reverse(tmp.begin(), tmp.end());
        answer.push_back(tmp);
    }
    return answer;
*/