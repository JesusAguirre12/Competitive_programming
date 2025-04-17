//100 pts
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
long long escribiendo(long long C, vector<long long>& numeros){
    ll n = numeros.size();
    vector<bool> used(n,0); 
    vector<ll> bests(n,C);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll best = LLONG_MAX;
        int p = 0;
        for(int u = 0; u < n; u++){
            if(!used[u] && bests[i] < best){
                best = bests[i];
                p = u;
            }
        }
        ans+=best;
        used[p] = 1;
        for(int v = 0; v < n; v++){
            if(!used[v]){
                ll g = __gcd(numeros[p], numeros[v]);
                ll cost = (numeros[p]/g+numeros[v]/g);
                if(cost < bests[v]){
                    bests[v]=cost;
                }
            }
        }
    }
    return ans;
}