#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    long long que1_sum = 0;
    long long que2_sum = 0;
    deque <int> que1;
    deque <int> que2;
    
    for(int i = 0; i < queue1.size(); i++) {
        que1_sum += queue1[i];
        que2_sum += queue2[i];
        que1.push_back(queue1[i]);
        que2.push_back(queue2[i]);
    }
    
    for(int i = 0; i < queue1.size() * 4; i++) {
        if (que1_sum == que2_sum) {
            return i;
        }
        if (que1_sum > que2_sum) {
            int data = que1.front();
            que1_sum -= data;
            que2_sum += data;
            que1.pop_front();
            que2.push_back(data);
        } else {
            int data = que2.front();
            que2_sum -= data;
            que1_sum += data;
            que2.pop_front();
            que1.push_back(data);
        }
    }
    
    return -1;
}