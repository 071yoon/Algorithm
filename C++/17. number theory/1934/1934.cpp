#include <stdio.h>
#include <vector>
#include <algorithm>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int num, cnt, max;

	std::vector <int> arr;
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++){
		scanf("%d", &num);
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	max = arr[1] - arr[0];
	for (int i = 2; i < cnt; i++){
		max = gcd(max, arr[i] - arr[i - 1]);
	}
	std::vector <int> ret;
	for (int i = 2; i * i <= max; i++){
		if (max % i == 0){
			if (i * i == max)
				ret.push_back(i);
			else{
				ret.push_back(i);
				ret.push_back(max / i);
			}
		}
	}
	ret.push_back(max);
	sort(ret.begin(), ret.end());
	for(int i = 0; i < ret.size(); i++)
		printf("%d ", ret[i]);
}