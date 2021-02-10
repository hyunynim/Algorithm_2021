#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> seq;
int d[3][303];
int go(int s, int cnt){
    if(s == n - 1)
        return seq[s];
    else if(s >= n)
        return -1e9;

    int & res = d[cnt][s];
    if(~res) return res;

    res = 0;
    if(cnt < 2)
        res = max(res, go(s + 1, cnt + 1) + seq[s]);
    return res = max(res, go(s + 2, 1) + seq[s]);
}
int main(){
    memset(d, -1, sizeof(d));

    scanf("%d", &n);
    seq.resize(n);
    for(int i = 0; i<n; ++i)
        scanf("%d", &seq[i]);
    
    printf("%d", max(go(0, 1), go(1, 1)));
}
