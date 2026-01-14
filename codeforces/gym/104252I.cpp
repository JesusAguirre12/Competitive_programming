#include <bits/stdc++.h>
#define int long long 
using namespace std;
vector<vector<int>> g(1e4+5); 
vector<int> dx = {-1,1,0,0}, dy={0,0,-1,1};
int32_t main(){
    int n,m;
    cin >> n  >> m;
    vector<vector<int>> mat(n,vector<int>(m,0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int x = 0; x < 4; x++){
                int nx=i+dx[x];
                int ny=j+dy[x];
                if(nx>-1 && ny >-1 && nx < n && ny < m){
                    g[mat[i][j]].push_back(mat[nx][ny]);
                }
            }
        }
    }
    const int k = n, q = m;
    vector<bitset<10001>> dp(n*m+1);
    for(int i = n*m; i >= 1; i--){
        dp[i][i]=1;
        for(auto nod : g[i]){
            if(nod > i){
                dp[i]|=dp[nod];
            }
        }
    }
    int ans=0;
    for(int i = 1; i <= n*m; i++){
        ans=max(ans,(int)dp[i].count());
    }
    cout << ans << '\n';
}