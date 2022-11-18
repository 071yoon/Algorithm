#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'longestChain' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY words as parameter.
 */

bool cmp(string a, string b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int longestChain(vector<string> words) {
    // <words[i], max cnt>
    map <string,int> m;
    sort(words.begin(), words.end(), cmp);
    int ret = 0;
    
    for(int i = 0; i < words.size(); i++) {
        m[words[i]] = 1;
        for(int j = 0; j < words[i].size(); j++) {
            string tmp_word = words[i];
            tmp_word.erase(tmp_word.begin() + j);
            auto it = m.find(tmp_word);
            if(it == m.end()) continue ;
            m[words[i]] = max(m[words[i]], it->second + 1);
        }
        ret = max(ret, m[words[i]]);
    }
    return ret;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string words_count_temp;
    getline(cin, words_count_temp);

    int words_count = stoi(ltrim(rtrim(words_count_temp)));

    vector<string> words(words_count);

    for (int i = 0; i < words_count; i++) {
        string words_item;
        getline(cin, words_item);

        words[i] = words_item;
    }

    int result = longestChain(words);

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
