#include <iostream>
using namespace std;
#define MAXN 21
int a[MAXN][4][4], b[MAXN][4][4];
bool row(int n){
	for(int i = 0; i < 4; i++){
		int total = 0;
		for(int j = 0; j < 4; j++)
			total += b[n][i][j];
		if(total == 4)	return true;
	}
	return false;
}
bool col(int n){
	for(int j = 0; j < 4; j++){
		int total = 0;
		for(int i = 0; i < 4; i++)
			total += b[n][i][j];
		if(total == 4)	return true;
	}
	return false;
}

bool ldia(int n){
	int total = 0;
	for(int i = 0; i < 4; i++)
		total += b[n][i][i];
	if(total == 4)	return true;
	else	return false;
}

bool rdia(int n){
	int total = 0;
	for(int i = 0; i < 4; i++)
		total += b[n][i][3-i];
	if(total == 4)	return true;
	else	return false;
}

int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	
	char C;
	int n, v;
	cin >> C >> n;
	for(int i = 0; i < n; i++){
		cin >> C;
		for(int j = 0; j < 16; j++){
			cin >> a[i][j/4][j%4];
		}
	}
	cin >> C;
	bool bingo = false;
	for(int p = 0; p < 16; p++){
		cin >> v;
		cout << v << ' ';
		for(int k = 0; k < n; k++){
			for(int i = 0; i < 4; i++){
				for(int j = 0; j < 4; j++){
					if(a[k][i][j] == v){
						b[k][i][j] = true;
						break;
					}
				}
			}
			if(row(k) || col(k) || ldia(k) || rdia(k)){
				bingo = true;
				cout << (char)('A'+k) << ' ';
			}

		}
		if(bingo){
			cout << '\n';
			break;
		}	
	}
	return 0;
}