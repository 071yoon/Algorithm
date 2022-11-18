#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'maxLength' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER k
 */

int maxLength(vector<int> a, int k) {
    int max_val = 0;
    int ret = 0;
    int dp = 0;
    for(int i = 0; i < a.size(); i++){
        max_val += a[i];
        while(max_val > k) {
            max_val -= a[dp];
            dp++;
        }
        ret = max(ret, i - dp + 1);
    }
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_count_temp;
    getline(cin, a_count_temp);

    int a_count = stoi(ltrim(rtrim(a_count_temp)));

    vector<int> a(a_count);

    for (int i = 0; i < a_count; i++) {
        string a_item_temp;
        getline(cin, a_item_temp);

        int a_item = stoi(ltrim(rtrim(a_item_temp)));

        a[i] = a_item;
    }

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    int result = maxLength(a, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
