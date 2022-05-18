#include <iostream>
using namespace std;
int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	char C[5][5], D[5][5];
	char A[5][5] = {{'a','b','c','d','e'},
					{'f', 'g', 'h', 'i', 'j'},
					{'k', 'l', 'm', 'n', 'o'},
					{'p', 'r', 's', 't', 'u'},
					{'v', 'w', 'x', 'y', 'z'}};


	int B[5][5] = {{'E','X','A','M','P'},
					{'L', 'B', 'C', 'D', 'F'},
					{'G', 'H', 'I', 'J', 'K'},
					{'N', 'O', 'R', 'S', 'T'},
					{'U', 'V', 'W', 'Y', 'Z'}};
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			D[i][j] = A[i][j];
			C[i][j] = B[i][j];
		}
	}

	int n;
	cin >> n;
	string s1, s2;
	cin >> s1;
	for(int k = n-1; k >= 0; k--){
		s2 += s1[k];
	}
	if(int(s2[0]-'A') > 25){
		for(int k = 0; k < n; k+=2){
			int i1, j1, i2, j2;
			for(int i = 0; i < 5; i++){
				for(int j = 0; j < 5; j++){
					if(s2[k] == A[i][j]){
						i1 = i;
						j1 = j;
					}
					if(s2[k+1] == A[i][j]){
						i2 = i;
						j2 = j;
					}
				}
			}
			cout << (char)B[i1][j2] << (char)B[i2][j1];
		}
	} else {
		for(int k = 0; k < n; k+=2){
			int i1, j1, i2, j2;
			for(int i = 0; i < 5; i++){
				for(int j = 0; j < 5; j++){
					if(s2[k] == B[i][j]){
						i1 = i;
						j1 = j;
					}
					if(s2[k+1] == B[i][j]){
						i2 = i;
						j2 = j;
					}
				}
			}
			cout << A[i1][j2] << A[i2][j1];
		}
	}
	cout << '\n';
	return 0;
}