#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pt pair<ll, ll>
#define x first
#define y second
ll dist(pt a, pt b){
    return (b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y);
}
int main() {
    ll n;
    cin >> n;
    vector<pt> v(n);
    for(ll i = 0; i < n; i++){cin >> v[i].x >> v[i].y;}
    ll d = LLONG_MAX;
    sort(v.begin(), v.end());
    set<pt> s = {{v[0].y, v[0].x}};
    ll j = 0;
    for(ll i = 1; i < n; i++){
        ll r=ceil(sqrt(d));
        while(j<i&&v[j].x<v[i].x-r){
            s.erase({v[j].y,v[j].x});
            j++;
        }
        auto l=s.lower_bound({v[i].y-r,0LL});
        auto u=s.upper_bound({v[i].y+r,0LL});
        for(auto it=l;it!=u;it++){
            d = min(d, dist({it->second,it->first},v[i]));
        }
        s.insert({v[i].y,v[i].x});
    }
    cout << d;
}
