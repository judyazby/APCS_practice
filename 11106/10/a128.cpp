#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
#define MAXN 10002
// #define DEBUG
int s[MAXN];
vector<int> ball[MAXN];

int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int a, b;
	for(int i = 1; i <= n; i++)
		s[i] = 10;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		if(s[a] >= s[b]){
			s[a] += s[b];
			ball[a].push_back(b);
			for(int j = 0; j < ball[b].size(); j++)
				ball[a].push_back(ball[b][j]);
		} else {
			s[b] += s[a];
			ball[b].push_back(a);
			for(int j = 0; j < ball[a].size(); j++)
				ball[b].push_back(ball[a][j]);
		}

	}
	
	#ifdef DEBUG
		for(int i = 1; i <= n; i++)
			cout << s[i] << (i == n?'\n':' ');
	#endif

	int x, mx = 0;
	for(int i = 1; i <= n; i++){
		if(s[i] > mx){
			x = i;
			mx = s[i];
		}
	}
	cout << x << '\n';
	ball[x].push_back(x);
	sort(ball[x].begin(), ball[x].end());
	for(int i = 0; i < ball[x].size(); i++)
		cout << ball[x][i] << (i == ball[x].size()-1?'\n':' ');

	return 0;
}