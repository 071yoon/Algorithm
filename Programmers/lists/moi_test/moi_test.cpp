#include <string>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
	if (a.first == b.first)
		return a.second > b.second;
}

int one[5] = {1, 2, 3, 4, 5};
int two[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int three[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
	int tmp[3] = {0};
	for(int i = 0; i < answers.size(); i++){
		if (answers[i] == one[i % 5]) tmp[0]++;
		if (answers[i] == two[i % 8]) tmp[1]++;
		if (answers[i] == three[i % 10]) tmp[2]++;
	}
	if (tmp[0] == tmp[1] == tmp[2]){
		answer.push_back(1);
		answer.push_back(2);
		answer.push_back(3);
	}
	else if (tmp[0] == tmp[1] && tmp[1] < tmp[2]){
		answer.push_back(1);
		answer.push_back(2);
	}
	else if (tmp[1] == tmp[2] && tmp[1] < tmp[0]){
		answer.push_back(1);
		answer.push_back(2);
	}
	else if (tmp[0] == tmp[2] && tmp[2] < tmp[1]){
		answer.push_back(0);
		answer.push_back(2);
	}
	else if (tmp[0] > tmp[2] && tmp[0] > tmp[1])
		answer.push_back(0);
	else if (tmp[1] > tmp[2] && tmp[1] > tmp[0])
		answer.push_back(1);
	else
		answer.push_back(2);

    return answer;
}