#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define MAXM 50005
// #define DEBUG
string s[MAXM];

// 尋找陣列s內是否有指定字串ss
bool has_str(int n, string ss){
  int l = 0, r = n-1;
  while(l <= r){
    int m = (l+r) / 2;
    if(s[m] == ss)  return true;
    else if(s[m] < ss)  l = m+1;
    else  r = m-1;
  }
  return false;
}

bool has_str_lo(int n, string ss){
  int idx = lower_bound(s, s+n, ss) - s;
  if(s[idx] == ss)  return true;
  else  return false;
}

int main(){
  ios::sync_with_stdio();
  cin.tie(0);
  int m;
  cin >> m;
  for(int i = 0; i < m; i++)
    cin >> s[i];
  // 法一：sort搭配二分搜尋土方法
  sort(s, s+m);
  int cnt = 0;

  // 時間複雜度：m*nlogn
  for(int i = 0; i < m; i++){
    // 對於某一支籤，一一檢查中間的子字串是否出現在s串列裡。
    // 考量到aaaaa等特殊情況，須一個一個檢查。

    // 舉例：7字元，8字元都是比對最多3字：0, 01, 012，提取中間剩下的字串。 
    for(int j = 1; j < (s[i].size()+1)/2; j++){
      string s1 = s[i].substr(0, j);
      string s2 = s[i].substr(s[i].size()-j, j);

      // 一旦取到中間字串，在陣列s使用二分搜尋。
      if(s1 == s2){
        string ss = s[i].substr(j, s[i].size() - 2*j);
        if(has_str_lo(m, ss)){
        // if(has_str(m, ss)){
          cnt++;
          #ifdef DEBUG
            cout << ss << " in " << s[i] << '\n';
          #endif
        } 
      }
    }
  }

  cout << cnt << '\n';
  return 0;
}