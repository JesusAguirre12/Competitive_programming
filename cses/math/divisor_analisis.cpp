#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int modexp=mod-1;
const ll  m=2LL*modexp;
ll binpow(ll a, ll b){
    a %= mod;
    ll res=1;
    while(b){
        if(b & 1)res=(res*a)%mod;
        a=(a*a) % mod;
        b>>=1;
    }
    return res;
}
ll modinv(ll a){
    return binpow(a, mod-2);
}
int main(){
    int n;
    cin >> n;
    vector<pair<ll,ll>>fac(n);
    for(int i = 0; i < n; i++){
        cin >> fac[i].first >> fac[i].second;
    }
    ll totdiv = 1, totsum = 1;
    ll dd = 1;
    for(auto &pe : fac){
        ll p = pe.first, e = pe.second;
        totdiv=totdiv*(e+1)%mod;
        dd=dd*(e+1)%m;
        ll num=(binpow(p, e+1)+mod-1)%mod;
        totsum=totsum*(num*modinv(p-1)%mod)%mod;
    }
 
    ll prodDivs = 1;
    for(auto &pe : fac){
        ll p = pe.first, e = pe.second;
        prodDivs = prodDivs*binpow(p,((((e%m)*dd)%m)/2)%modexp)%mod;
    }
    cout << totdiv << ' ' << totsum << ' ' << prodDivs << "\n";
    return 0;
}