#include <iostream>
using namespace std;
#define MAXN 505
#define DEBUG
bool a[MAXN][MAXN];
int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	int n, m, r;
	cin >> n >> m >> r;
	for(int i = 0; i < r; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int inc_x = 0, inc_y = 0;
		if(x1 != x2)
			inc_x = (x2-x1)/abs(x2-x1);
		if(y1 != y2)
			inc_y = (y2-y1)/abs(y2-y1);
		int chk = 0;
		while(!(x1 == x2 && y1 == y2)){
			a[x1][y1] = 1;
			x1 += inc_x;
			y1 += inc_y;
		}
		a[x2][y2] = 1;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cnt += a[i][j];
		}
	}
	cout << cnt << '\n';
	return 0;
}