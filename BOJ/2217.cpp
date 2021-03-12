#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    int n; scanf("%d", &n);
    vector<ll> seq(n);
    for(int i = 0; i<n; ++i)
        scanf("%lld", &seq[i]);
    sort(seq.begin(), seq.end());
    reverse(seq.begin(), seq.end());
    ll ans = 0;
    for(int i = 0; i<n; ++i){
        ans = max(ans, (i + 1) * seq[i]);
    }
    printf("%lld", ans);
}
