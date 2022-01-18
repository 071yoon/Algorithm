#include <iostream>
#include <vector>
using namespace std;

int tree[10000];
void postorder(int start, int end){
	if (start == end){
		cout << tree[start] << "\n";
		return ;
	}
	int index = start + 1;
	while (index <= end){
		if (tree[start] < tree[index]){
			break ;
		}
		else
			index++;
	}
	index -= 1;
	if (start + 1 <= index)
		postorder(start + 1, index);
	if (index + 1 <= end)
		postorder(index + 1, end);
	cout << tree[start] << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int num;
	int input = 0;
	while (cin >> num){
		tree[input++] = num;
	}
	postorder(0, input - 1);

	return (0);
}