#include<bits/stdc++.h>
using namespace std;
int d[1010101];
int go(int s){
    if(s == 1) return 0;

    int & res = d[s];
    if(~res) return res;

    res = 1e9;

    if(s % 3 == 0)
        res = min(res, go(s / 3) + 1);
    if(s % 2 == 0)
        res = min(res, go(s / 2) + 1);
    return res = min(res, go(s - 1) + 1);
}
int main(){
    memset(d, -1, sizeof(d));
    int n; scanf("%d", &n);
    printf("%d", go(n));
}
