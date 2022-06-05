#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 200005
int a[MAXN], b[MAXN], c[MAXN];
int main(){
  ios::sync_with_stdio();
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    b[i] = a[i];
  }
  sort(a, a+n);
  int len = unique(a, a+n) - a;
  // 把b的數字換成離散化後的index
  for(int i = 0; i < n; i++)
    b[i] = lower_bound(a, a+len, b[i]) - a;

  int total = 0, ans = 0;
  for(int i = 0; i < n; i++){
    // 先刪掉前面超過的
    if(i > m-1){
      c[b[i-m]]--;
      if(c[b[i-m]] == 0)  total--;
    }
    // 再加入自己，算有幾個
    if(c[b[i]] == 0)  total++;
    c[b[i]] += 1;
    // 最後計算是否長度為m的連續區段符合條件
    if(total == m)  ans++;
  }
  cout << ans << '\n';
  
  return 0;
}