#include <bits/stdc++.h>
#define int long long 
using namespace std; 
const int mod = 1e9+7;
int32_t main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto&i:v){
        cin >> i;
    }
    sort(v.begin(), v.end());
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1e9));
    for(int i = 0; i < n; i++){
        dp[i][i] = 0;
    }
    for(int i = 2; i <= n; i++){
        for(int l = 0; l+i <= n; l++) {
            int r=l+i-1;
            dp[l][r]=min(dp[l+1][r],dp[l][r-1])+(v[r]-v[l]);
        }
    }

    cout << dp[0][n-1] << '\n';
}   