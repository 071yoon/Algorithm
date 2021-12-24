#include <iostream>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);



/*
	int num1, num2;
	cin >> num1 >> num2;	
	int up_2, up_5, down_2, down_5;
	up_2 = 0; up_5 = 0; down_2 = 0; down_5 = 0;
	int cnt_2 = 0; int cnt_5 = 0;
	if (num2 == 0){
		cout << "0\n";
		return (0);
	}
	else if (num2 > num1 / 2)
		num2 = num1 - num2;
	for (int i = (num1 - num2 + 1); i <= num1; i++){
		int tmp1 = i;
		while (tmp1 % 5 == 0){
			cnt_5++;
			tmp1 /= 5;
		}
		int tmp2 = i;
		while (tmp1 % 2 == 0){
			cnt_2++;
			tmp1 /= 2;
		}
	}
	for (int i = 1; i <= num2; i++){
		int tmp1 = i;
		while (tmp1 % 5 == 0){
			cnt_5--;
			tmp1 /= 5;
		}
		int tmp2 = i;
		while (tmp1 % 2 == 0){
			cnt_2--;
			tmp1 /= 2;
		}
	}
	int max;
	if (cnt_2 <= cnt_5)
		max = cnt_2;
	else
		max = cnt_5;
	cout << max;


*/
}