#include <deque>
#include <iostream>
#include <vector>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cnt, num, inputs;
	deque <int> que;
	cin >> cnt >> num;
	for (int i = 1; i < cnt + 1; i++){
		que.push_back(i);
	}
	deque <int> order;
	for (int i = 0; i < num; i++){
		cin >> inputs;
		order.push_back(inputs);
	}
	int cntr = 0;
	int tester1, tester2;
	while (!(order.empty())){
		if (order.front() == que.front()){
			order.pop_front();
			que.pop_front();
		}
		else{
			deque <int> right = que;
			deque <int> left = que;
			tester1 = 0; tester2 = 0;
			while (!(right.front() == order.front())){
				right.push_back(right.front());
				right.pop_front();
				tester1++;
			}
			while (!(left.front() == order.front())){
				left.push_front(left.back());
				left.pop_back();
				tester2++;
			}
			que = right;
			if (tester1 > tester2){
				cntr += tester2;
			}
			else{
				cntr += tester1;
			}
		}
	}
	cout << cntr;
}
/*
-------
At
10 3
2 9 5
-------
1 2 3 4 5 6 7 8 9 10 -> org
3 4 5 6 7 8 9 10 1   -> 2 times
10 1 3 4 5 6 7 8     -> 2 times
6 7 8 10 1 3 4       -> 4 tiems
or
6 7 8 0 1 2 3 -> 4 times
-------
At
10 10
1 6 3 2 7 9 8 4 10 5
-------
1 2 3 4 5 6 7 8 9 10 -> org
2 3 4 5 6 7 8 9 10   -> 0 times
7 8 9 10 2 3 4 5     -> 4 times
4 5 7 8 9 10 2       -> 3 times
4 5 7 8 9 10         -> 1 times
8 9 10 4 5           -> 2 times
10 4 5 8             -> 1 times
10 4 5               -> 1 times
5 10                 -> 1 times
5                    -> 1 times
0                       14times
*/