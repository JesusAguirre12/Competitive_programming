#include <bits/stdc++.h>
using namespace std;
struct ind{
    int a,b,c;
};
int main(){
    int n;
    cin >> n;
    vector<ind> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].a >> v[i].b >> v[i].c;
    }
    vector<vector<int>> dp(n+1,vector<int>(3,0));
    for(int i = 1; i <= n; i++){
        dp[i][0]=max(dp[i-1][1],dp[i-1][2])+v[i-1].a;
        dp[i][1]=max(dp[i-1][0],dp[i-1][2])+v[i-1].b;
        dp[i][2]=max(dp[i-1][1],dp[i-1][0])+v[i-1].c;
    }
    cout << max({dp[n][0],dp[n][1],dp[n][2]});
}