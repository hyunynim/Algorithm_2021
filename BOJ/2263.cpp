#include<bits/stdc++.h>
using namespace std;

vector<int> in, post;
int s = -1;
void getRoot(int left, int right, int prevRt) {
	if (left == right) {
		return;
	}
	int rtInd = find(in.begin(), in.end(), prevRt) - in.begin();
	int l = rtInd - left;
	int r = right - rtInd;
	if (l) {
		int nr = post[l - 1];
		post.erase(post.begin() + l - 1);
		printf("%d ", nr);
		getRoot(left, rtInd - 1, nr);
	}
	if (r) {
		int nr = post[r - 1];
		post.erase(post.begin() + r - 1);
		printf("%d ", nr);
		getRoot(rtInd + 1, right, nr);
	}
}

int main() {
	int n, tmp;
	scanf("%d", &n);
	in.resize(n);
	post.resize(n);

	for (int i = 0; i < n; ++i)
		scanf("%d", &in[i]);

	for (int i = 0; i < n; ++i)
		scanf("%d", &post[i]);
	s = post[n - 1];
	printf("%d ", s);
	getRoot(0, n - 1, s);
}
