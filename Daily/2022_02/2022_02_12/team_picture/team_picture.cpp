#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
string original;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    original = "ACFJMNRT";
    do{
        int flag = 0;
        for(int i = 0; i < n; i++){
            int index1, index2;
            for(int j = 0; j < 8; j++){
                if (data[i][0] == original[j])
                    index1 = j;
                if (data[i][2] == original[j])
                    index2 = j;
            }
            if (data[i][3] == '='){
                if (abs(index1 - index2) == data[i][4] - '0' + 1)
                    continue ;
                else{
                    flag = 1;
                    break ;
                }
            }
            else if (data[i][3] == '>'){
                if (abs(index1 - index2) > data[i][4] - '0' + 1)
                    continue ;
                else{
                    flag = 1;
                    break ;
                }
            }
            else{//<
                if (abs(index1 - index2) < data[i][4] - '0' + 1)
                    continue ;
                else{
                    flag = 1;
                    break ;
                }
            }
        }
        if (flag == 0)
            answer++;
    }while(next_permutation(original.begin(), original.end()));
    return answer;
}

int main(){
	vector <string> data;
	data.push_back("N~F=0");
	data.push_back("R~T>2");
	cout << solution(2, data);
}

/*
우선 data 사이즈만큼 friend[0] 과 friend[2] 가 friend[4] 만큼 friend[3] 조건 만족해야됨
ACFJMNR 을 next_permutation 으로 반복 돌림
friend 반복만큼 확인해서 다 맞아야 경우의 수 추가
*/