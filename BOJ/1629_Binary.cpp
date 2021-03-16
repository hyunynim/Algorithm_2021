#include<cstdio>
typedef long long ll;
ll pow(ll a, ll b, ll c){
    ll res = 1;
    while(b){
        if(b % 2){
            res *= a;
            res %= c;
        }
        a *= a;
        a %= c;
        b /= 2;
    }
    return res;
}

int main(){
    ll a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    printf("%lld", pow(a,b,c));
}
