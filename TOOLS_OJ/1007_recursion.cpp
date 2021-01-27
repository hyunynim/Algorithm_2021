#include<bits/stdc++.h>
using namespace std;
int n; 
vector<int> seq;
bool go(int l, int r){
    if(l >= n && r >= n) return 0;
    else if(r >= n)
        return go(l + 1, l + 2);
    
    if(seq[l] + seq[r] == 0){
        printf("%d %d", seq[l], seq[r]);
        return 1;
    }
    
    return go(l, r + 1);
}
int main(){
    scanf("%d", &n);
    seq.resize(n);
    for(int i = 0; i<n; ++i)
        scanf("%d", &seq[i]);
    if(go(0, 1)) return 0;
    else printf("-1");
}
