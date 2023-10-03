#include <iostream>
using namespace std;

bool prime_numbers[1000001] = {false};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    
    prime_numbers[0] = true;
    prime_numbers[1] = true;
    for(int i = 2; i * i < 1000001; i++) {
        if (prime_numbers[i]) continue;
        for(int j = i * i; j < 1000001; j += i) {
            prime_numbers[j] = true;
        }
    }

    int num;
    while(1) {
        cin >> num;
        bool flag = false;
        if (num == 0) return 0;
        for(int i = 3; i < num; i += 2) {
            if (!prime_numbers[i] && !prime_numbers[num - i]) {
                flag = true;
                cout << num << " = " << i << " + " << num - i << "\n";
                break;
            }
        }
        if (!flag) {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
} 