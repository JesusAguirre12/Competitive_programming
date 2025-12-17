#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1<<17;
vector<int> tree(2*maxn,-1e9);
int n;
void build(vector<int>&vet){
    for(int i = 0; i < vet.size(); i++){
        tree[maxn+i]=vet[i];
    }
    for(int i = maxn-1; i>0; i--){
        tree[i]=max(tree[i<<1],tree[i<<1|1]);
    }
}
int query(int l,int r){
    int ans = -1e9;
    l+=maxn;
    r+=maxn;
    while(l<r){
        if(l&1) ans=max(ans,tree[l++]);
        if(r&1) ans=max(ans,tree[--r]);
        l>>=1;
        r>>=1;
    }
    return ans;
}
int main(){
    int m;
    cin >> n >> m;
    vector<int> v(n);
    for(auto &i:v){
        cin>>i;
    }
    build(v);
    int ans=0;
    for(int i = 0; i < m; i++){
        int a,b;
        cin>>a>>b;
        int l = min(a,b);
        int r = max(a,b);
        if(query(l, r-1)<=v[a-1]){
            ans++;
        }
    }
    cout << ans;
}
 