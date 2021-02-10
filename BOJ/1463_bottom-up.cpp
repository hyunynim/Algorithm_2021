#include<bits/stdc++.h>
using namespace std;
int d[1010101];
int main(){
    int n; scanf("%d", &n);
    for(int i = 2; i<=n; ++i){
        d[i] = 1e9;
        if(i % 2 == 0)
            d[i] = min(d[i], d[i / 2] + 1);
        if(i % 3 == 0)
            d[i] = min(d[i], d[i / 3] + 1);
        d[i] = min(d[i], d[i - 1] + 1);
    }
    printf("%d", d[n]);
}
