#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int n;
vector<int> vet;
vector<vector<int>> tree;
void build(int n){
    for(int i = 0; i < n; i++){
        tree[n+i]={vet[i]};
    }
    for(int i = n-1; i > 0; i--){
        merge(tree[i<<1].begin(), tree[i<<1].end(), tree[i<<1|1].begin(), tree[i<<1|1].end(), back_inserter(tree[i]));
    }
}
int query_less(int l, int r, int val){
    l+=n;
    r+=n;
    int ans=0;
    while(l<r){
        if(l&1){
            ans+=lower_bound(tree[l].begin(),tree[l].end(),val)-tree[l].begin();
            l++;
        }
        if(r&1){
            r--;
            ans+=lower_bound(tree[r].begin(),tree[r].end(),val)-tree[r].begin();
        }
        l>>=1;
        r>>=1;
    }
    return ans;
}
int query_great(int l, int r, int val){
    l+=n;
    r+=n;
    int ans=0;
    while(l<r){
        if(l&1){
            ans+=tree[l].end()-upper_bound(tree[l].begin(),tree[l].end(),val);
            l++;
        }
        if(r&1){
            r--;
            ans+=tree[r].end()-upper_bound(tree[r].begin(),tree[r].end(),val);
        }
        l>>=1;
        r>>=1;
    }
    return ans;
}
int main(){
    cin >> n;
    vet.resize(n);
    tree.resize(2*n+1);
    for(auto&i:vet){
        cin>>i;
    }
    build(n);
    ll ans=0;
    for(int i = 1; i < n-1; i++){
        ans+=(ll)(query_great(0,i,vet[i]))*(ll)(query_less(i+1,n,vet[i]));
    }
    cout << ans;
}