#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'findRange' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER num as parameter.
 */

string findMax(string tmp) {
    int i = 0;
    for(i = 0; i < tmp.size(); i++) {
        if(tmp[i] != '9') {
            break;
        }
    }
    if(i == tmp.size()) return tmp;
    string change_val = "";
    change_val += tmp[i];
    return (regex_replace(tmp, regex(change_val), "9"));
}

string findMin(string tmp) {
    string change_val = "";
    // first starts with 1
    if(tmp[0] == '1') {
        int j;
        for(j = 1; j < tmp.size(); j++) {
            if(tmp[j] != '0' && tmp[j] != '1') {
                break;
            }
        }
        if(j == tmp.size()) return tmp;
        change_val += tmp[j];
        return (regex_replace(tmp, regex(change_val), "0"));
    }
    change_val += tmp[0];
    return (regex_replace(tmp, regex(change_val), "1"));
}

long findRange(int num) {
    string tmp = "";
    int tnum = num;
    while(tnum) {
        tmp += (tnum % 10) + '0';
        tnum /= 10;
    }
    reverse(tmp.begin(), tmp.end());
    string max_val = findMax(tmp);
    string min_val = findMin(tmp);
    return stol(max_val) - stol(min_val);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string num_temp;
    getline(cin, num_temp);

    int num = stoi(ltrim(rtrim(num_temp)));

    long result = findRange(num);

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
