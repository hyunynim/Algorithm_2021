#include<bits/stdc++.h>
using namespace std;
const int len = 3;
const int b = (1 << len) - 1;
void SetCube(int& cube, int idx, int num) {
	int tmp = (b << (idx * len));
	cube &= (~tmp);
	cube |= (num << (idx * len));
}
int GetCube(int cube, int idx) {
	int res = (cube >> (idx * len)) & b;
	return res;
}
bool Check(int cube, int k) {
	int f = cube & b;
	for(int i = 0; i<k; ++i){
		if ((cube & b) != f) return 0;
		cube >>= len;
	}
	return 1;
}
int d[1 << 24];
vector<int> adj[11];
int main() {
	Check(16777215, 8);
	int n, k; scanf("%d %d", &n, &k);
	int cube = 0;
	for (int i = 0; i < n; ++i) {
		int num; scanf("%d", &num);
		SetCube(cube, i, num);
	}
	for (int i = 1; i <= k; ++i) {
		int num; scanf("%d", &num);
		for (int j = 0; j < num; ++j) {
			int c; scanf("%d", &c);
			adj[i].push_back(c - 1);
		}
	}
	queue<int> q;
	q.push(cube);
	d[cube] = 1;
	while (q.size()) {
		int cur = q.front(); q.pop();
		if (Check(cur, n)) {
			printf("%d", d[cur] - 1);
			return 0;
		}
		for (int i = 1; i <= k; ++i) {
			cube = cur;
			for (auto c : adj[i]) 
				SetCube(cube, c, (GetCube(cube, c) + i) % 5);

			if (d[cube] == 0) {
				d[cube] = d[cur] + 1;
				q.push(cube);
			}
		}
	}
	printf("-1");
}
