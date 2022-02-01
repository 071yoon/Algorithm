#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<string> lines;
    string line;

    while (getline(cin, line)){
        lines.push_back(line);
    }

    for (int i = 0; i < lines.size(); i++)
        cout << lines[i] << "\n";

}