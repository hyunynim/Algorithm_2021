#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m; scanf("%d %d", &n, &m);
    vector<int> seq(n);
    for(int i = 0; i<n; ++i)
        scanf("%d", &seq[i]);
    
    vector<int> sum(n);
    for(int i = 0; i<n; ++i){
        sum[i] = seq[i];
        if(i)
            sum[i] += sum[i - 1];
    }
    for(int i = 0; i<m; ++i){
        int a, b; scanf("%d %d", &a, &b);
        --a; --b;
        printf("%d\n", sum[b] - (a - 1 >= 0 ? sum[a - 1] : 0));
    }
}
