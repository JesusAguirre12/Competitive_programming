#include <bits/stdc++.h>
#define x first
#define y second 
#define int long long 
using namespace std;
void open(string name = ""){
    cin.tie(0)->sync_with_stdio(0); 
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int32_t main(){
    open("placas");
    int n, k;
    cin >>k >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].x >> v[i].y;
    }
    vector<int> cost(1<<n,0);
    for(int i = 1; i < (1<<n); i++){
        int mx=-1e9, mix=1e9, my=-1e9, miy=1e9; 
        for(int j = 0; j < n; j++){
            if(i&(1<<j)){
                mx=max(mx,v[j].x);
                mix=min(mix,v[j].x);
                my=max(my,v[j].y);
                miy=min(miy,v[j].y);
            }
        }
        cost[i]=2*((mx-mix+2*k)+(my-miy+2*k));
    }
    vector<int> dp((1<<n),1e9);
    dp[0]=0;
    for(int i = 0; i < (1<<n); i++){
        for(int j = i;j; j=(j-1)&i){
            dp[i]=min(dp[i],dp[i^j]+cost[j]);
        }
    }
    cout << dp[(1<<n)-1];
}