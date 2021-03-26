#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool chk(ll mid, ll a, ll b, ll v){
	return a * mid - b * (mid - 1) >= v;
}
int main(){
	ll a, b, v; scanf("%lld %lld %lld", &a, &b, &v);	
	ll l = 1, r = 3e9;
	ll ans = 3e9;
	while(l <= r){
		ll mid = (l + r) /2 ;
		if(chk(mid, a, b, v)){
			ans = min(mid, ans);
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	printf("%lld", ans);
}
