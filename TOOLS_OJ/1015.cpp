#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; scanf("%d", &n);
    int origin = n, rev = 0;
    while(n){
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    printf("%d", rev == origin);
}
