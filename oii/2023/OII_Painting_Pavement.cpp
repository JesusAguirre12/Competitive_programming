#include <bits/stdc++.h>
#define pb push_back
using namespace std;
struct rans{
    int a,b,c;
};
struct bloque{
    int val,l,r;
};
vector<bloque> v;
vector<rans> ans;
vector<int> cur;
/*
void pinta(int l, int r, int c){
    bool ok=0;
    for(int i = l; i <= r; i++){
        if(cur[i]!=c){
            ok=1;
            break;
        }
    }
    if(ok){
        ans.pb({v[l].l+1,v[r].r+1,c});
        for(int i = l; i <= r; i++){
            cur[i]=c;
        }
    }
}
*/
void build(int l, int r, vector<vector<int>>&idx, vector<vector<int>>&op, int c){
    if(r<l){
        return;
    }
    if(c!=v[l].val){
        ans.pb({v[l].l+1,v[r].r+1,v[l].val});
        c=v[l].val;
    }
    if(op[l][r]==0){
        build(l+1,r,idx,op,c);
    }else{
        int k=idx[l][r];
        build(l+1,k-1,idx,op,c);
        build(k,r,idx,op,c);
    }
}
int main(){
    int n;
    cin>> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n;){
        int j=i;
        while(j<n && a[i]==a[j]){
            j++;
        }
        v.pb({a[i],i,j-1});
        i=j;
    }
    n=v.size();
    vector<vector<int>> dp(n,vector<int>(n,1e9));
    vector<vector<int>> op(n,vector<int>(n,-1)), idx(n,vector<int>(n,-1));
    cur.assign(n,-1);
    for(int i = 0; i < n; i++){
        dp[i][i]=1;
        op[i][i]=0;
        idx[i][i]=i;
    }
    for(int j = 2; j <= n; j++){
        for(int l = 0; l <= n-j; l++){
            int r=l+j-1;
            dp[l][r]=1+dp[l+1][r];
            op[l][r]=0;
            idx[l][r]=l;
            for(int i = l+1; i <= r; i++){
                if(v[l].val==v[i].val){
                    int k= (i==l+1 ? 0 : dp[l+1][i-1])+dp[i][r];
                    if(k < dp[l][r]){
                        dp[l][r]=k;
                        op[l][r]=1;
                        idx[l][r]=i;
                    }
                }
            }
        }
    }
    cout << dp[0][n-1] << '\n';
    build(0,n-1,idx,op,-1);
    for(auto [a,b,c] : ans){
        cout << a << ' ' << b << ' ' << c << '\n';
    }
}

ahi por fin dio AC