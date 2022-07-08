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

// bool operator<(const Move& x, const Move& y)
// {
//     if(x.a == y.a && x.b == y.b)	return x.change != y.change;
//     if(x.a == y.a)	return x.b < y.b;
// 	return x.a < y.a;
// }

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
			int idx = lower_bound(mv, mv+m, x, cmp) - mv;
			if(idx == m || (mv[idx].a != mv[i].b || mv[idx].b != mv[i].a))	continue;
			else{
				// cout << "idx = " << idx << ", Move " << mv[i].a << " and " << mv[i].b << '\n';
				cnt++;
				mv[i].change = true;
				mv[idx].change = true;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}