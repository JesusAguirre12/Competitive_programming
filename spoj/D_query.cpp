#include <bits/stdc++.h>
#define s second
#define f first
#define ll long long 
using namespace std;
struct ft{
    int N;
    vector<int> bit;
    ft(int n=0){ init(n); }
    void init(int n){
        N = n;
        bit.assign(N+1, 0);
    }
    void add(int idx, int val){
        for (; idx <= N; idx += idx & -idx)
            bit[idx] += val;
    }
    int sum(int idx){
        int r = 0;
        for (; idx > 0; idx -= idx & -idx)
            r += bit[idx];
        return r;
    }
    void range_add(int l, int r, int val){
        add(l, val);
        if (r + 1 <= N) add(r + 1, -val);
    }
    int point_query(int x){
        return sum(x);
    }
    int query(int l, int r){ return sum(r) - sum(l-1); }
};
 
int main(){
    int n;
    cin>> n;
    vector<int> vec(n+1),lap(1e6+1,0);
    for(int i = 1; i <= n; i++){
      cin >> vec[i];
    }
    int q;
    cin >> q;
    vector<pair<pair<int,int>,int>> v(q);
    for(int i = 0; i < q; i++){
      cin>> v[i].f.f >> v[i].f.s;
      v[i].s=i;
    }
    sort(v.begin(), v.end(), [&](pair<pair<int,int>,int> x, pair<pair<int,int>,int> y) {
        return x.f.s < y.f.s;
    });
    int curr=0;
    ft bit(n);
    vector<int> ans(q);
    for(auto el : v){
        while(curr<el.f.s){
            curr++;
            if(lap[vec[curr]]!=0){
                bit.add(lap[vec[curr]],-1);
            }
            bit.add(curr,+1);
            lap[vec[curr]]=curr;
        }
        ans[el.s]=bit.query(el.f.f,el.f.s);
    }
    for(auto i : ans){
        cout << i << '\n';
    }
}
 