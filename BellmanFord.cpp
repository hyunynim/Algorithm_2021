#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct EDGE{
    ll from, to, w;
};
vector<EDGE> edges;
const ll inf = 1e9;
vector<ll> BellmanFord(int v, int st){
    vector<ll> res(v + 1);
    fill(res.begin(), res.end(), inf);
    res[st] = 0;
    for(int  i = 1; i<=v; ++i){
        for(int j = 0; j < edges.size(); ++j){
            ll s = edges[j].from, t = edges[j].to, w = edges[j].w;
            if(res[s] != inf && res[t] > res[s] + w){
                if(i == v){
                    res[0] = -1;
                    return res;
                }
                res[t] = res[s] + w;
            }
        }
    }
    return res;
}
