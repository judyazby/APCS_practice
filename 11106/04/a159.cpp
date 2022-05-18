#include <iostream>
using namespace std;
#define MAXN 105
int a[MAXN][MAXN];
int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	int n;
	while(cin >> n && n != 0){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> a[i][j];

		for(int i = 0; i < n; i++)	a[i][n] = 0;
		for(int j = 0; j < n; j++)	a[n][j] = 0;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(a[i][j]){
					a[i][n]++;
					a[n][j]++;
				}	
			}
		}

		int ridx, cidx, rcnt = 0, ccnt = 0;
		for(int i = 0; i < n; i++){
			if(a[i][n] % 2){
				ridx = i;
				rcnt++;
			}
		}
		for(int j = 0; j < n; j++){
			if(a[n][j] % 2){
				cidx = j;
				ccnt++;
			}
		}
		if(rcnt + ccnt == 0)	
			cout << "OK\n";
		else if(rcnt == 1 && ccnt == 1)
			cout << "Change bit (" << ridx+1 << "," << cidx+1 << ")\n";
		else
			cout << "Corrupt\n";
	}

	return 0;
}