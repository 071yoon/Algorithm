#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>

bool compare(std::string a, std::string b){
	if (a.size() == b.size())
		return a < b;
	else
		return a.size()<b.size();
}

std::vector <std::string> v;
int main(){
	int cnt;
	char *str = new char[50];

	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++){
		scanf("%s", str);
		v.push_back(str);
	}
	sort(v.begin(), v.end(), compare);
	std::vector<std::string>::iterator iter;
	std::vector<std::string>::iterator end_iter;
	end_iter = unique(v.begin(), v.end());

    for(iter = v.begin(); iter !=end_iter ; iter++){
        printf("%s\n", (*iter).c_str()); //C++ style string을 C style로 출력.
    }

}