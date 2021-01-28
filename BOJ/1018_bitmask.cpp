#include<bits/stdc++.h>
using namespace std;
int n, m;
typedef long long ll;
ll board[55];
int CheckBoard(int x, int y) {
	ll chk[2] = {0};

	for (int i = 0; i < 8; ++i)
			chk[i % 2] |= (1LL << i);

	int res = 1e9;
	for (int k = 0; k < 2; ++k) {
		int cnt = 0;
		for (int i = 0; i < 8; ++i) {
			ll cur = ((board[x + i] >> y) & ((1LL << 8) - 1)) ^ chk[k];
			while(cur){
				++cnt;
				cur -= (cur & (-cur));
			}
			chk[k] ^= (1LL << 8) - 1;
		}
		res = min(res, cnt);
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
				board[i] |= (1LL << j);
		}
	}

	int mm = 1e9;

	for (int i = 0; i <= n - 8; ++i) 
		for(int j = 0; j<= m - 8; ++j)
			mm = min(mm, CheckBoard(i, j));
	printf("%d", mm);
}
