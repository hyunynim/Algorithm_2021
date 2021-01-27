#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	priority_queue<int> l, r;
	for (int i = 0; i < n; ++i) {
		int num; scanf("%d", &num);
		if (l.size() && l.top() < num)
			r.push(-num);
		else
			l.push(num);

		if (l.size() < r.size()) {
			l.push(-r.top());
			r.pop();
		}
		else if (l.size() - r.size() > 1) {
			r.push(-l.top());
			l.pop();
		}
		printf("%d ", l.top());
	}
}
