#include <bits/stdc++.h>
#define int long long 
using namespace std;
int32_t main(){
    int n;
    cin >> n;
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        if(n%2==0){
            dp[i][i]=-v[i];
        }else{
            dp[i][i]=v[i];
        }
    }
    for(int l = n-1; l>= 1; l--){
        for(int j = 1; j <= n-l; j++){
            int r=l+j; 
            if((n-j)&1){
                dp[l][r]=max(dp[l+1][r]+v[l],dp[l][r-1]+v[r]);
            }else{
                dp[l][r]=min(dp[l+1][r]-v[l], dp[l][r-1]-v[r]);
            }
        }
    }
    cout << dp[1][n];
}