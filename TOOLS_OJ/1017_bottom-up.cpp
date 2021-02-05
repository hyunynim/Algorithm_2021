#include<bits/stdc++.h>
using namespace std;
bool d[2020][2020];
char str[2020];
int main() {
	int n; scanf("%d", &n);
	scanf("%s", str);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j + i < n; ++j) {
			if (i < 2)
				d[j][j + i] = (str[j] == str[i + j]);
			else
				d[j][j + i] = (str[j] == str[i + j] && d[j + 1][i + j - 1]);
		}
	}
	int m; scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int l, r; scanf("%d %d", &l, &r);
		if (d[l][r])
			puts("1");
		else
			puts("0");
	}
}
