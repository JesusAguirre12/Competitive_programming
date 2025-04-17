#include <bits/stdc++.h>
#pragma GCC optimize("Ofast, unroll-all-loops")
#define ll long long 
using namespace std;
ll comp(ll x, const vector<int>&tinta) {
    ll c=0;
    while(x>0){
        int d=x%10;
        c+=tinta[d];
        x/=10;
    }
    return c;
}
const ll INF = 1e18;
int editora(vector<int> &tinta, vector<long long> &articulos, string &ordenamiento) {
    int n = articulos.size();
    vector<ll> sp(1<<n, 0);
    sp[0<<0] = 0;
    for(int m = 1; m < 1<<n; m++){
        ll j=__builtin_ctz(m);
        sp[m]=sp[m^(1<<j)]+articulos[j];
    }

    vector<ll> cs(1<<n, 0);
    for(int m = 0; m < 1<<n; m++){
        ll var = 1+sp[m];
        cs[m] = comp(var,tinta);
    }
    vector<ll> dp(1<<n, INF);
    vector<ll> cc(1<<n,-1), parent(1<<n, -1);
    dp[0<<0] = 0;
    for(int m = 0; m < 1<<n; m++){
        ll add = cs[m];
        for(int j = 0; j < n; j++){
            if(!(m&(1<<j))){
                ll curr = dp[m]+add;
                if(curr < dp[m|(1<<j)]){
                    dp[m|(1<<j)] = curr;
                    cc[m|(1<<j)] = j;
                    parent[m|(1<<j)] = m;
                }
            }
        }
    }
    ll ans = dp[(1<<n)-1];
    ll m = (1<<n)-1;
    while(m){
        ll art=cc[m];
        ordenamiento.push_back('A'+art);
        m=parent[m];
    }
    reverse(ordenamiento.begin(),ordenamiento.end());
    return ans;
}