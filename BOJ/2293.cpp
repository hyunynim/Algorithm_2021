#include<bits/stdc++.h>
using namespace std;
int d[10101];
int main(){
	int n, k;scanf("%d %d", &n, &k);
	vector<int> seq(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &seq[i]);
	d[0] = 1;

	for (int i = 0; i < n; i++)	
		for (int j = seq[i]; j <= k; j++)		
			d[j] += d[j - seq[i]];

	printf("%d", d[k]);

}
