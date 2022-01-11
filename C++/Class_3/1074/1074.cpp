#include <iostream>
#include <math.h>
using namespace std;

long long sqr;
long long ret;
void recur(long long sqr, int row, int col){
	long long tmp = pow(sqr, 2);
	if (sqr == 1)
		return ;
	if (row >= sqr / 2 && col >= sqr / 2){//4D
		ret += (tmp / 4) * 3;
		recur(sqr / 2, row - sqr / 2, col - sqr / 2);
	}
	else if (row >= sqr / 2 && col <= sqr / 2){//3D
		ret += (tmp / 4) * 2;
		recur(sqr / 2, row - sqr / 2, col);
	}
	else if (row <= sqr / 2 && col >= sqr / 2){//2D
		ret += (tmp / 4) * 1;
		recur(sqr / 2, row, col - sqr / 2);
	}
	else{//1D
		recur(sqr / 2, row, col);
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int num, row, col;
	cin >> num >> row >> col;
	sqr = pow(2, num);
	ret = 0;
	recur(sqr, row, col);
	cout << ret << "\n";
}