#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d[2020][2020];
const ll mod = 1e9 + 7;
int main(){
    d[0][0] = 1;
    for(int i = 1; i<2020; ++i){
        for(int j = 0; j<=i; ++j){
            if(0 < j)
                d[i][j] += d[i-1][j-1];
            d[i][j] += d[i-1][j];
            d[i][j] %= mod;
        }
    }
    int n, r; scanf("%d %d", &n, &r);
    printf("%lld", d[n][r]);
}
