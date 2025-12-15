#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn = 2e5+1;
int n;
vector<int>seba(2*maxn), juan(2*maxn);
void build(vector<int>& vet){
    for(int i = 0; i < n; i++){
        seba[n+i]=vet[i]+i+1;
        juan[n+i]=vet[i]-i-1;
    }
    for(int i = n-1; i> 0; i--){
        juan[i]=min(juan[i<<1],juan[i<<1|1]);
        seba[i]=min(seba[i<<1],seba[i<<1|1]);
    }
}
void update(int p, int val){
    juan[p+n]=val-p-1;
    seba[p+n]=val+p+1;
    p+=n;
    for(p>>=1;p>0;p>>=1){
        juan[p]=min(juan[p<<1],juan[p<<1|1]);
        seba[p]=min(seba[p<<1],seba[p<<1|1]);
    }
}
pair<int,int> query(int l, int r){
    l+=n;
    r+=n;
    int ans1=100000000;
    int ans2=100000000;
    while(l<r){
        if(l&1){
            ans1=min(juan[l],ans1);
            ans2=min(seba[l],ans2);
            l++;
        }
        if(r&1){
            r--;
            ans2=min(seba[r],ans2);
            ans1=min(juan[r],ans1);
        }
        l>>=1;
        r>>=1;
    }
    //cout << ans1 << ' ' << ans2 << '\n';
    return {ans1,ans2};
}
int32_t main(){
    int q;
    cin>> n >> q;
    vector<int> vet(n);
    for(int i = 0; i < n; i++){
        cin >> vet[i];
    }
    build(vet);
    while(q--){
        int t;
        cin >> t;
        if(t==1){
            int val, pos;
            cin >> pos>> val;
            update(pos-1,val);
        }else{
            int val;
            cin >> val;
            int ans2 = query(val,n).second;
            int ans1 = query(0,val).first;
            cout << min(ans1+val,ans2-val) << '\n';
        }
    }
}