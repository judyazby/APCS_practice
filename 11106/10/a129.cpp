#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
#define MAXN 100005
pair<int, int> tree[MAXN];
int happy = 0;

void merge_sort(pair<int, int> t[], int l, int r){
	if(l == r)	return;
	int m = (l+r)/2;
	merge_sort(t, l, m);
	merge_sort(t, m+1, r);
	happy = max(happy, tree[l].second - tree[r].second);

	// merge
	pair<int, int> tmp[r-l+1];
	int p = l, q = m+1, idx = 0;
	while(p <= m && q <= r){
		int f, s;
		if(tree[p].second >= tree[q].second){
			tmp[idx++] = make_pair(tree[p].first, tree[p].second);
			p++;
		} else {
			tmp[idx++] = make_pair(tree[q].first, tree[q].second);
			q++;
		}
	}
	while(p <= m){
		tmp[idx++] = make_pair(tree[p].first, tree[p].second);
		p++;
	}
	while(q <= r){
		tmp[idx++] = make_pair(tree[q].first, tree[q].second);
		q++;
	}

	for(int i = 0; i < r-l+1; i++){
		t[i+l] = tmp[i];
	}
	return;
}


int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	int n;
	cin >> n;

	int x, y, h;
	for(int i = 0; i < n; i++){
		cin >> x >> y >> h;
		tree[i].first = x*x + y*y;
		tree[i].second = h;
	}
	sort(tree, tree+n);
	merge_sort(tree, 0, n-1);
	cout << happy << '\n';
	return 0;
}