#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; scanf("%d", &n);
    vector<int> seq(n);
    map<int, int> cnt;
    for(int i = 0; i<n; ++i){
        scanf("%d", &seq[i]);
        ++cnt[seq[i]];
    }
    sort(seq.begin(), seq.end());
    seq.erase(unique(seq.begin(), seq.end()), seq.end());
    for(auto i : seq)
        printf("%d %d\n", i, cnt[i]);
}
