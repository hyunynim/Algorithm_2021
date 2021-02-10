#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m; scanf("%d %d", &n, &m);
    vector<int> seq(n + 1);
    for(int i = 1; i<=n; ++i){
        scanf("%d", &seq[i]);
        seq[i] += seq[i-1];
    }
    for(int i = 0; i<m; ++i){
        int a, b; scanf("%d %d", &a, &b);
        printf("%d\n", seq[b] - seq[a - 1]);
    }
}
