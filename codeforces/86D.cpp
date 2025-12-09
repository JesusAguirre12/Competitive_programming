#include <bits/stdc++.h>
#define ll long long 
using namespace std;
struct query{
    int l, r, idx;
};
vector<int> cont(1e6+5,0);
ll curr=0LL;
void add(int val){
    curr+=(ll)((2LL*(ll)(cont[val])+1LL)*(ll)(val));
    cont[val]++;
}
void rem(int val){
    curr-=(ll)((2LL*(ll)(cont[val])-1LL)*(ll)(val));
    cont[val]--;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n>>k;
    vector<int> v(n);
    vector<query> q(k);
    for(auto&i:v){
        cin >>i;
    }
    for(int i = 0; i < k; i++){
        cin >> q[i].l >> q[i].r;
        q[i].l--;
        q[i].r--;
        q[i].idx=i;
    }
    int sq=sqrt(n);
    sort(q.begin(),q.end(),[&](query a, query b){
       if(a.l/sq != b.l/sq) return a.l < b.l;
       return a.r<b.r;
    });
    int lo=q[0].l, hi=q[0].r;
    for(int i = lo; i <= hi; i++){
        add(v[i]);
    }
    vector<ll> ans(k);
    ans[q[0].idx]=curr;
    for(auto e : q){
        while(lo<e.l){
            rem(v[lo]);
            lo++;
        }
        while(hi>e.r){
            rem(v[hi]);
            hi--;
        }
        while(hi<e.r){
            hi++;
            add(v[hi]);
        }
        while(lo>e.l){
            lo--;
            add(v[lo]);
        }
        ans[e.idx]=curr;
    }
    for(auto i : ans){
        cout << i << '\n';
    }
}