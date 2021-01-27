#include<bits/stdc++.h>
using namespace std;
vector<int> seq;
int ans, n, s;
void go(int toPick, int sum, int prev){
        if(toPick == 0){
                ans += (sum == s);
                return;
        }
        for(int i = prev + 1; i<n; ++i)
                go(toPick - 1, sum + seq[i], i);
}
int main(){
        scanf("%d %d", &n, &s);
        seq.resize(n);
        for(int i = 0; i<n; ++i)
                scanf("%d", &seq[i]);
        for(int i = 1; i<=n; ++i)
                go(i, 0, -1);
        printf("%d", ans);
}
