#include <bits/stdc++.h>
#define int long long 
using namespace std; 
struct ind{
    int w,c;
};
int32_t main(){
    int n,w;
    cin >> n >> w;
    vector<ind> v(n);
    int tot=0;
    for(int i = 0; i < n; i++){
        cin >> v[i].w >> v[i].c;
        tot+=v[i].c;
    }
    vector<int> dp(tot+1,1e18);
    dp[0]=0;
    for(int i = 1; i <= n; i++){
        for(int j = tot; j >= v[i-1].c; j--){
            dp[j]=min(dp[j],dp[j-v[i-1].c]+v[i-1].w);
        }
    }
    int ans=-1;
    for(int i = 1; i <= tot; i++){
        if(dp[i]<=w){
            ans=i;
        }
    }
    cout << ans << '\n';
}