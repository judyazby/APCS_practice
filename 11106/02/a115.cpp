#include <iostream>
#include <utility>
// #define DEBUG
using namespace std;
int a[5][5], s[5][5];
pair<int,int> loc[26];

bool check_row(int r, int c){
  bool line = true;
  for(int j = 0; j < 5; j++){
    if(c == j)  continue;
    if(a[r][j]){
      line = false;
      break;
    }
  }
  return line;
}

bool check_col(int r, int c){
  bool line = true;
  for(int i = 0; i < 5; i++){
    if(r == i)  continue;
    if(a[i][c]){
      line = false;
      break;
    }
  }
  return line;
}

bool check_ldia(int r, int c){
  if(r != c)
    return false;
  bool line = true;
  for(int i = 0; i < 5; i++){
    if(r == i)  continue;
    if(a[i][i]){
      line = false;
      break;
    }
  } 
  return line;
}

bool check_rdia(int r, int c){
  if(r+c != 4)
    return false;
  bool line = true;
  for(int i = 0; i < 5; i++){
    if(r == i)  continue;
    if(a[i][4-i]){
      line = false;
      break;
    }
  } 
  return line;
}

int main(){
  ios::sync_with_stdio();
  cin.tie(0);
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      cin >> a[i][j];
      loc[a[i][j]].first = i;
      loc[a[i][j]].second = j;
    }
  }
  int n;
  while(cin >> n && n != -1){
    a[loc[n].first][loc[n].second] = 0;
  }
  

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      if(a[i][j] == 0)  continue;
      s[i][j] += check_row(i, j) + check_col(i, j) 
      + check_ldia(i, j) + check_rdia(i, j);
    }
  }
  #ifdef DEBUG
    cout << "-----table-----\n";
    for(int i = 0; i < 5; i++){
      for(int j = 0; j < 5; j++){
        cout << a[i][j] << '\t';
      }
      cout << '\n';
    }

    cout << "-----score-----\n";
    for(int i = 0; i < 5; i++){
      for(int j = 0; j < 5; j++){
        cout << s[i][j] << '\t';
      }
      cout << '\n';
    }
  #endif

  int mi = 0, mj = 0, v = 26;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      if(a[i][j] == 0)  continue;
      if(v == 26 || s[i][j] > s[mi][mj]){
        mi = i;
        mj = j;
        v = a[mi][mj];
      } else if(s[i][j] == s[mi][mj] && a[i][j] < a[mi][mj]){
        mi = i;
        mj = j;
        v = a[mi][mj];
      }
    }
  }
  #ifdef DEBUG
    cout << mi << ' ' << mj << '\n';
  #endif
  cout << a[mi][mj] << '\n';
  
  return 0;
}