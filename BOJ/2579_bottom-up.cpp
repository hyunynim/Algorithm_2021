#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> seq;
int d[3][303];
int main(){
    scanf("%d", &n);
    seq.resize(n + 1);
    for(int i = 1; i<=n; ++i)
        scanf("%d", &seq[i]);

    d[1][1] = seq[1];
   
    for(int i = 2; i<= n; ++i){
        d[1][i] = max({d[1][i], d[1][i - 2] + seq[i], d[2][i - 2] + seq[i]});
        d[2][i] = max(d[2][i], d[1][i - 1] + seq[i]);
    }
    printf("%d", max(d[1][n], d[2][n]));
}
