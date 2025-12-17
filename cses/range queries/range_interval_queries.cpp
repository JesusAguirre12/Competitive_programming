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
int query(int l, int r, int c, int d){
    l+=n;
    r+=n;
    int ans=0;
    while(l<r){
        if(l&1){
            ans+=upper_bound(tree[l].begin(),tree[l].end(),d) - lower_bound(tree[l].begin(),tree[l].end(),c);
            l++;
        }
        if(r&1){
            r--;
            ans+=upper_bound(tree[r].begin(),tree[r].end(),d) - lower_bound(tree[r].begin(),tree[r].end(),c);
        }
        l>>=1;
        r>>=1;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> n >> q;
    vet.resize(n);
    tree.resize(2*n+1);
    for(auto&i:vet){
        cin>>i;
    }
    build(n);
    while(q--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        cout << query(a-1,b,c,d) << '\n';
    }
}