#include<bits/stdc++.h>
using namespace std;
int n, m;
typedef long long ll;
ll board[2][55];
int CheckBoard(int x, int y) {
	ll b = 0, w = 0;
	for (int i = 0; i < 8; ++i) {
		if (i % 2)
			b |= (1LL << i);
		else
			w |= (1LL << i);
	}
	int res = 1e9;
	for (int k = 0; k < 2; ++k) {
		int sum = 0;
		for (int i = 0; i < 8; ++i) {
			ll cur1 = (board[0][x + i] >> y)& b;
			ll cur2 = (board[1][x + i] >> y)& w;
			while (b) {

			}
		}

		res = min(res, sum);
		b ^= (1LL << m) - 1;
		w ^= (1LL << m) - 1;
	}
	return res;
}
int main() {
	scanf("%d %d", &n, &m);
	char msg[55];
	for (int i = 0; i < n; ++i) {
		scanf("%s", msg);
		for (int j = 0; msg[j]; ++j) {
			if (msg[j] == 'W')
				board[0][i] |= (1LL << i);
			else
				board[1][i] |= (1LL << i);
		}
	}

	int mm = 1e9;

	for (int i = 0; i <= n - 8; ++i) {

	}
	printf("%d", mm);
}
