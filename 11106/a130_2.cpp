#include <iostream>
#include <algorithm>
#define MAXM 1002
using namespace std;
struct Move{
	int a, b;
	bool change;
};
Move mv[MAXM];
int cmp(Move x, Move y){
	if(x.a == y.a)	return x.b <= y.b;
	return x.a <= y.a;
}

int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	int n, m;
	cin >> n;
	while(n--){
		for(int i = 0; i < MAXM; i++){
			mv[i].a = 0;
			mv[i].b = 0;
			mv[i].change = false;
		}

		cin >> m;
		for(int i = 0; i < m; i++)
			cin >> mv[i].a >> mv[i].b;
		
		sort(mv, mv+m, cmp);
		// for(int i = 0; i < m; i++)
		// 	cout << "Sorted " << mv[i].a << " and " << mv[i].b << '\n';

		int cnt = 0;
		for(int i = 0; i < m; i++){
			if(mv[i].change)	continue;
			Move x = {mv[i].b, mv[i].a, false};
			int l = 0, r = m-1, idx;
			while(l <= r){
				idx = (l+r)/2;
				if(mv[idx].a < x.a || mv[idx].a == x.a and mv[idx].b < x.b)	l = idx+1;
				else if (mv[idx].a > x.a || mv[idx].a == x.a and mv[idx].b > x.b) r = idx-1;
				else if (mv[idx].change)	l = idx+1;	//不一定？這樣還沒問題，就表示兩部門一人以上的調動不會發生。
				else	break;
			}

			// int idx = lower_bound(mv, mv+m, x) - mv;
			if(mv[idx].a == x.a && mv[idx].b == x.b && !mv[idx].change){
				cnt++;
				mv[i].change = true;
				mv[idx].change = true;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}