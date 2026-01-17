#include <bits/stdc++.h>
#define int long long 
using namespace std;
struct node{
    int vmax=-1e9-1;
    int pmax=-1e18;
    int pmin=1e18;
};
vector<node> tree(4e5+5);
int n;
vector<int> vet;
vector<int> pref(2e5+5,0);
void build(){
    for(int i = 0; i < (n<<1)+2; i++){
        tree[i] = node();
    }
    for(int i = 0; i < n+1; i++){
        tree[n+i+1].vmax=vet[i];
        tree[n+i+1].pmax=pref[i];
        tree[n+i+1].pmin=pref[i];
    }
    for(int i = n; i > 0; i--){
        tree[i].vmax=max(tree[i<<1].vmax,tree[i<<1|1].vmax);
        tree[i].pmax=max(tree[i<<1].pmax,tree[i<<1|1].pmax);
        tree[i].pmin=min(tree[i<<1].pmin,tree[i<<1|1].pmin);
    }
}
 
node query(int l,int r){
    l+=n+1;
    r+=n+1;
    int ans1=-1e18;
    int ans2=-1e18;
    int ans3=1e18;
    while(l<r){
        if(l&1){
            ans1=max(tree[l].vmax,ans1);
            ans2=max(tree[l].pmax,ans2);
            ans3=min(tree[l].pmin,ans3);
            l++;
        }
        if(r&1){
            r--;
            ans1=max(tree[r].vmax,ans1);
            ans2=max(tree[r].pmax,ans2);
            ans3=min(tree[r].pmin,ans3);
        }
        l>>=1;
        r>>=1;
    }
    node ans;
    ans.vmax=ans1;
    ans.pmax=ans2;
    ans.pmin=ans3;
    return ans;
}
pair<int,int> getidx(int x, int idx){
    int lo=idx,hi=n-1;
    int l=idx,r=idx;
    while(lo<=hi){
        int mid = (lo+hi)>>1;
        node ans = query(idx,mid+1);
        if(ans.vmax<=x){
            r=mid;
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }
    lo=0,hi=idx;
    while(lo<=hi){
        int mid = (lo+hi)>>1;
        node ans = query(mid,idx+1);
        if(ans.vmax<=x){
            l=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    return {l,r};
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>> t;
    while(t--){
        cin >> n;
        vet.resize(n);
        pref[0]=0;
        for(int i = 0; i < n; i++){
            cin >> vet[i];
            pref[i+1]=pref[i]+vet[i];
        } 
        build();
        bool ok=1;
        for(int i = 0; i < n; i++){
            auto [l,r] = getidx(vet[i],i);
            int lo = query(l,i+1).pmin;
            int hi = query(i+1,r+2).pmax;
            if(hi-lo>vet[i]){
                ok=0;
                break;
            }
        }
        if(ok){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}