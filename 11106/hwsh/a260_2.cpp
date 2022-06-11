#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
#define MAXM 50005
// #define DEBUG
set<string> s;


int main(){
  ios::sync_with_stdio();
  cin.tie(0);
  int m;
  cin >> m;

  string st;
  for(int i = 0; i < m; i++){
    cin >> st;
    s.insert(st);
  }
  // 法二：set自己會sort
  int cnt = 0;

  // 時間複雜度：m*nlogn
  for(string str:s){
    // 對於某一支籤，一一檢查中間的子字串是否出現在s串列裡。
    // 考量到aaaaa等特殊情況，須一個一個檢查。

    // 舉例：7字元，8字元都是比對最多3字：0, 01, 012，提取中間剩下的字串。 
    for(int j = 1; j < (str.size()+1)/2; j++){
      string s1 = str.substr(0, j);
      string s2 = str.substr(str.size()-j, j);

      // 一旦取到中間字串，在陣列s使用二分搜尋。
      if(s1 == s2){
        string ss = str.substr(j, str.size() - 2*j);
        if(s.find(ss) != s.end()){
        // if(has_str(m, ss)){
          cnt++;
          #ifdef DEBUG
            cout << ss << " in " << str << '\n';
          #endif
        } 
      }
    }
  }

  cout << cnt << '\n';
  return 0;
}