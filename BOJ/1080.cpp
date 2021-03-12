#include<bits/stdc++.h>
using namespace std;
int mat[2][123][123], ans;
void rev(int a, int b) {
	for (int i = a; i < a + 3; ++i) 
		for (int j = b; j < b + 3; ++j)
			mat[0][i][j] = 1 - mat[0][i][j];
    ++ans;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int k = 0; k < 2; ++k) 
		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < m; ++j) 
				scanf("%1d", &mat[k][i][j]);
    
	for (int i = 0; i < n - 2; ++i) 
		for (int j = 0; j < m - 2; ++j) 
			if (mat[0][i][j] != mat[1][i][j]) 
				rev(i, j);
    
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j) 
			if (mat[0][i][j] != mat[1][i][j]) 
                ans = -1;
    
	printf("%d", ans);
}
