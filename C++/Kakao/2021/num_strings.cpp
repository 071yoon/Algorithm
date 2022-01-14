#include <iostream>
#include <string>
using namespace std;

int solution(string s){
	int answer;

	while(s.find("zero") != -1)
		s.replace(s.find("zero"), 4, "0");
	while(s.find("one") != -1)
		s.replace(s.find("one"), 3, "1");
	while(s.find("two") != -1)
		s.replace(s.find("two"), 3, "2");
	while(s.find("three") != -1)
		s.replace(s.find("three"), 5, "3");
	while(s.find("four") != -1)
		s.replace(s.find("four"), 4, "4");
	while(s.find("five") != -1)
		s.replace(s.find("five"), 4, "5");
	while(s.find("six") != -1)
		s.replace(s.find("six"), 3, "6");
	while(s.find("seven") != -1)
		s.replace(s.find("seven"), 5, "7");
	while(s.find("eight") != -1)
		s.replace(s.find("eight"), 5, "8");
	while(s.find("nine") != -1)
		s.replace(s.find("nine"), 4, "9");
	answer = stoi(s);
	return answer;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;
	cout << solution(s) << "\n";
}