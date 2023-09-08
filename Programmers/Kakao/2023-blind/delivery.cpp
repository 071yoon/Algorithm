#include <string>
#include <iostream>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    int delivery_last;
    int pickup_last;

    vector<int> deliveries_copy = deliveries;
    vector<int> pickups_copy = pickups;

    for(int i = n - 1; i >= 0; i--) {
        if (deliveries_copy[i] != 0) {
            delivery_last = i;
            break;
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        if (pickups_copy[i] != 0) {
            pickup_last = i;
            break;
        }
    }
    long long answer = 0;
    while (1) {
        if (delivery_last <= 0 && deliveries_copy[0] == 0 && pickup_last <= 0 && pickups_copy[0] == 0){
            break;
        }
        int max_position = max(delivery_last, pickup_last);
        int delivery_cap = cap;
        int pickup_cap = cap;
        answer += 2 * (max_position + 1);
        for(int i = delivery_last; i >= 0; i--) {
            if (deliveries_copy[i] > delivery_cap) {
                deliveries_copy[i] -= delivery_cap;
                break;
            }
            if (deliveries_copy[i] <= delivery_cap) {
                delivery_cap -= deliveries_copy[i];
                deliveries_copy[i] = 0;
                delivery_last -= 1;
            }
            if (delivery_cap == 0 && deliveries_copy[i] != 0) break;
        }
        for(int i = pickup_last; i >= 0; i--) {
            if (pickups_copy[i] > pickup_cap) {
                pickups_copy[i] -= pickup_cap;
                break;
            }
            if (pickups_copy[i] <= pickup_cap) {
                pickup_cap -= pickups_copy[i];
                pickups_copy[i] = 0;
                pickup_last -= 1;
            }
            if (pickup_cap == 0 && pickups_copy[i] != 0) break;
        }
    }
    return answer;
}

int main(){
    int cap = 4;
    int n = 5;
    vector <int> deliveries;
    vector <int> pickups;
    deliveries.push_back(1);
    deliveries.push_back(0);
    deliveries.push_back(3);
    deliveries.push_back(1);
    deliveries.push_back(2);

    pickups.push_back(0);
    pickups.push_back(3);
    pickups.push_back(0);
    pickups.push_back(4);
    pickups.push_back(0);

    solution(cap, n, deliveries, pickups);
    return 0;
}