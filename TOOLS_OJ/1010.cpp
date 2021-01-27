#include<bits/stdc++.h>
using namespace std;
int d[2020][2020];
const int mod = 1e9 + 7;
int main(){
    d[0][0] = 1;
    for(int i = 1; i<15; ++i){
        for(int j = 0; j<=i; ++j){
            if(0 < j)
                d[i][j] += d[i-1][j-1];
            d[i][j] += d[i-1][j];
        }
    }
    int n, r; scanf("%d %d", &n, &r);
    printf("%d", d[n][r]);
}
