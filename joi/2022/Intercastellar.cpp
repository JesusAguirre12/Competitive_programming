//100 pts
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<ll> tree(n,0), v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        ll val=__builtin_ctzll(v[i]);
        v[i]>>=val;
        if(i==0){
            tree[i]=(1LL<<val);
        }else{
            tree[i]=tree[i-1]+(1LL<<val);
        }
    }
    int q;
    cin >> q;
    while(q--){
        ll a;
        cin >> a;
        cout << v[lower_bound(tree.begin(),tree.end(),a)-tree.begin()] << '\n';
    }
}