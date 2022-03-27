#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
using namespace std;

double getArea(double x1, double x2, double x3, double y1, double y2, double y3){
	double res = x1 * y2 + x2 * y3 + x3 * y1;
	res += (y1 * x2 * -1 - y2 * x3 - y3 * x1);
	return (res / 2);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	pair<double, double> arr[10001];
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i].first >> arr[i].second;
	}
	double res = 0;
	for(int i = 1; i < n; i++){
		res += getArea(arr[0].first, arr[i - 1].first, arr[i].first, arr[0].second, arr[i - 1].second, arr[i].second);
	}
	printf("%.1f", abs(res));



}