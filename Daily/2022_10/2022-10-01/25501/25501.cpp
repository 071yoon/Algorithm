#include <iostream>
using namespace std;

int tmp = 0;

int isPali(string s){
  int len = s.length();
  tmp = 1;
  for(int i = 0; i < len / 2; i++){
    if(s[i] != s[len - i - 1]) 
      return 0;
    else {
      tmp++;
    }
  }
  return 1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int num;
  cin >> num;
  for(int i = 0; i < num; i++){
    string str;
    cin >> str;
    cout << isPali(str) << " " << tmp << "\n";
  }
}