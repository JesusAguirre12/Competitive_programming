#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n>> m;
    vector<vector<int>> dp(n,vector<int>(m,0));
    vector<vector<char>> mp(n, vector<char>(m));
    dp[0][0]=1;
    for(int i = 0; i < n; i++){
        for(int j = 0;j  < m; j++){
            cin >> mp[i][j];
            if(mp[i][j] == '#'){
                dp[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mp[i][j] == '.'){
                if(i > 0){
                    dp[i][j] += dp[i-1][j];
                }
                if(j > 0){
                    dp[i][j] += dp[i][j-1];
                }
            }
            dp[i][j] %= int(1e9+7);
        }
    }
    cout << dp[n-1][m-1];
}