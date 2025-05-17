//100pts
//codigo de honor al cumple de faggi
#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
using namespace std;
struct Node{
    vector<int> izq; 
    vector<int> der; 
};
vector<Node> faggi;
int n;
void build(const vector<pair<int,int>>& ranges){
    for(int i = 0; i < n; i++){
        faggi[i+n].izq.push_back(ranges[i].ff);
        faggi[i+n].der.push_back(ranges[i].ss);
    }
    for(int i = n-1; i > 0; i--){
        faggi[i].izq.resize(faggi[i<<1].izq.size()+faggi[i<<1|1].izq.size());
        merge(faggi[i<<1].izq.begin(), faggi[i<<1].izq.end(),
              faggi[i<<1|1].izq.begin(), faggi[i<<1|1].izq.end(),
              faggi[i].izq.begin());

        faggi[i].der.resize(faggi[i<<1].der.size()+faggi[i<<1|1].der.size());
        merge(faggi[i<<1].der.begin(), faggi[i<<1].der.end(),
              faggi[i<<1|1].der.begin(), faggi[i<<1|1].der.end(),
              faggi[i].der.begin());
    }
}
inline int cont(int idx, int x){
    int iz = upper_bound(faggi[idx].izq.begin(),faggi[idx].izq.end(), x)-faggi[idx].izq.begin();
    int de = lower_bound(faggi[idx].der.begin(),faggi[idx].der.end(), x)-faggi[idx].der.begin();
    return iz-de;
}
int query(int l, int r, int x){
    int res=0;
    for(l+=n,r+=n+1; l<r; l>>=1, r>>=1) {
        if(l & 1)res+=cont(l++,x);
        if(r & 1)res+=cont(--r,x);
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<pair<int,int>> vet1(n);
    for(int i = 0; i < n; i++){
        cin >> vet1[i].ff >> vet1[i].ss;
    }
    vector<int> mids(n), ord(n);
    for(int i = 0; i < n; i++){
        mids[i] = vet1[i].ff+vet1[i].ss;
        ord[i] = i;
    }
    sort(ord.begin(), ord.end(),[&](int a,int b){
        return mids[a] < mids[b];
    });
    vector<pair<int,int>> vet(n);
    vector<int> mids2(n);
    for(int i = 0; i < n; i++){
        int idx = ord[i];
        vet[i].ff=vet1[idx].ff*2;
        vet[i].ss=vet1[idx].ss*2;
        mids2[i]=mids[idx];       
    }
    mids.swap(mids2);
    faggi.assign(2*n, Node{});
    build(vet);
    ll ans = 0;
    for(int j = 0; j < n; j++){
        int faggi2 = vet[j].ff;       
        int faggi1 = mids[j];        
        int i1 = int(lower_bound(mids.begin(), mids.begin()+j, faggi2) - mids.begin());
        if(i1 < j){
            ans += query(i1, j-1, faggi1);
        }
    }
    cout << ans;
    return 0;
}