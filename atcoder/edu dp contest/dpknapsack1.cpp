#include <bits/stdc++.h>
#define int long long
using namespace std;
int maxcant = 101, maxp = 1e5+5;
const int maxn = 1e18+1;
vector<vector<int>> dp(maxcant, vector<int>(maxp, 0));
vector<int> peso(maxp), valor(maxp);
int32_t main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> peso[i] >> valor[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = peso[i]; j <= m; j++){
            dp[i][j] = -maxn;
        }
    }
    dp[0][0] = 0;
    int ans = -1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= peso[i]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-peso[i]]+valor[i]);
            }
            ans = max(dp[i][j], ans);
        }
    }
    cout << ans << '\n';
}