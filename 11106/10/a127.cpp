#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 102
int a[MAXN];
int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);
	cout << a[0] << ' ' << a[n-1];
	if(a[n-1] - a[0] == n-1)
		cout << " yes\n";
	else
		cout << " no\n";
	return 0;
}