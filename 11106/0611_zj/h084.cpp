#include <iostream>
#include <algorithm>
#define MAXN 200005
#define MAXK 5005
// #define DEBUG
using namespace std;
int h[MAXN], w[MAXK], tmp[MAXN];
int main(){
  ios::sync_with_stdio();
  cin.tie(0);
  int n, k;
  cin >> n >> k;

  for(int i = 0; i < n; i++){
    cin >> h[i];
    tmp[i] = h[i];
  }  
  for(int i = 0; i < k; i++)  cin >> w[i];
  sort(tmp, tmp+n, greater<int>());

  int hleft = 0, hright = tmp[0];
  #ifdef DEBUG
    cout << "hright = " << hright << '\n';
  #endif
  // 所需變數：檢查到哪個高度、已貼幾張海報、現在在哪個柵欄
  int hmid, kcnt = 0;
  while(hleft < hright){
    kcnt = 0;
    hmid = (hleft + hright+1)/2;// 重要雷點
    #ifdef DEBUG
      cout << "hright = " << hright << ", hleft = "<< hleft << '\n';
      cout << "hmid = " << hmid << '\n';
    #endif
    int wcnt = 0;
    for(int i = 0; i < n; i++){
      if(h[i] >= hmid)  wcnt++;
      else  wcnt = 0;
      if(wcnt == w[kcnt]){
        kcnt++;
        wcnt = 0;
      }
      if(kcnt == k) break;
    }
    #ifdef DEBUG
      cout << "kcnt = " << kcnt << '\n';
    #endif
    if(kcnt == k) hleft = hmid;
    else  hright = hmid-1;
  }
  cout << hleft << '\n';

  return 0;
}