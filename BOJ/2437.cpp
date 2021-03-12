#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	sort(seq.begin(), seq.end());
	
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		if (sum < seq[i] - 1) {
			printf("%d", sum + 1);
			
			return 0;
		}
		sum += seq[i];
	}
	printf("%d", sum + 1);
	return 0;
}
