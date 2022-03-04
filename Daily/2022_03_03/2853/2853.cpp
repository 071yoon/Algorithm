#include <vector>
#include <iostream>
using namespace std;

vector <int> vec;
int main()
{
	int N, a = 0, temp, boat = 0, num;
	cin >> N;

	for (int i = 0; i < N; i++){
		cin >> num;
		vec.push_back(num);
	}

	for (int i = 1; i < N; i++)
	{
		if (vec[i] == 0)
			continue;
		a = vec[i] - vec[0];
		temp = 1;
		for (int j = 1; j < N; j++)
		{
			if (vec[j] == 0)
				continue;
			if (vec[j] % a == 1)
			{
				temp += a;
				vec[j] = 0;
			}
		}
		if (temp != 1)
			boat++;
	}

	cout << boat;

	return 0;
}