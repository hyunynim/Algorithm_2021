#include<cstdio>
#include<algorithm>
using namespace std;

char msg[100][100] = { 0 };
long long chess[50] = { 0LL };
int minChess = 987654321;

void CheckChess(int sx, int sy) {
	int res[2] = { 0 };
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					if (msg[i + sy][j + sx] == 'W')
						res[0]++;
				}
				else {
					if (msg[i + sy][j + sx] == 'B')
						res[0]++;
				}
			}
			else {
				if (j % 2 == 0) {
					if (msg[i + sy][j + sx] == 'B')
						res[0]++;
				}
				else {
					if (msg[i + sy][j + sx] == 'W')
						res[0]++;
				}
			}
		}
	}

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					if (msg[i + sy][j + sx] != 'W')
						res[1]++;
				}
				else {
					if (msg[i + sy][j + sx] != 'B')
						res[1]++;
				}
			}
			else {
				if (j % 2 == 0) {
					if (msg[i + sy][j + sx] != 'B')
						res[1]++;
				}
				else {
					if (msg[i + sy][j + sx] != 'W')
						res[1]++;
				}
			}
		}
	}
	minChess = min(minChess, min(res[0], res[1]));
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", msg[i]);
	}
	for (int i = 0; i <= n - 8; ++i) {
		for (int j = 0; j <= m - 8; ++j) {
			CheckChess(j, i);
		}
	}
	printf("%d", minChess);
}
