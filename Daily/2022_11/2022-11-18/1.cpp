#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the 'getFinalString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string getFinalString(string s) {
    string s_cp = s;
    int n = s_cp.size();
    int i, j;
    for(i = 0, j = 0; i < n; i++) {
        s_cp[j++] = s_cp[i];
        if (j >= 3 && s_cp.substr(j - 3, 3) == "AWS") {
            j -= 3;
        }
    }
    if (s_cp.substr(0, j) == "") return "-1";
    return s_cp.substr(0, j);
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = getFinalString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
