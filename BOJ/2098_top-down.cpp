#include<bits/stdc++.h>
using namespace std;
int n, num, cost[20][20];
int d[1 << 16][16];
const int inf = 1e9;
int TSP(int s, int stat) {
	if (stat == (1 << n) - 1)
		return cost[s][0] ? cost[s][0] : inf;
	int & res = d[stat][s];
	if (res != -1) return res;
	res = inf;
	for (int i = 0; i < n; ++i) 
		if ((stat & (1 << i)) == 0 && cost[s][i])
			res = min(res, TSP(i, stat | (1 << i)) + cost[s][i]);
	return res;
}
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j) 
			scanf("%d", &cost[i][j]);
	printf("%d", TSP(0, 1));
}
