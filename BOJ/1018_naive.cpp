#include<bits/stdc++.h>
using namespace std;
int n, m;
char board[55][55];
int CheckBoard(int x, int y) {
	char chess[2][2] = { {'B', 'W'}, {'W', 'B'} };
	int res = 1e9;
	for (int k = 0; k < 2; ++k) {
		int sum = 0;
		for (int i = 0; i < 8; ++i) 
			for (int j = 0; j < 8; ++j) 
				if (board[i + x][j + y] != chess[i % 2][j % 2]) ++sum;
		res = min(res, sum);
		swap(chess[0], chess[1]);
	}
	return res;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%s", board[i]);

	int mm = 1e9;

	for (int i = 0; i <= n - 8; ++i) {
		for (int j = 0; j <= m - 8; ++j) {
			mm = min(mm, CheckBoard(i, j));
		}
	}
	printf("%d", mm);
}
