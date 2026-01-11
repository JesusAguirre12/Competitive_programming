#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>> n;
    vector<char> v;
    char last='0',curr='0';
    for(int i = 0; i < n; i++){
        char x;
        cin >> x;
        last=curr;
        curr=x;
        if(curr!=last){
            v.push_back(curr);
        }
    }
    n=v.size();
    vector<vector<int>> dp(n,vector<int>(n,1e9));
    for(int i = 0; i < n; i++){
        dp[i][i]=1;
    }
    for(int j = 2; j <= n; j++){
        for(int l = 0; l <= n-j; l++){
            int r=l+j-1;
            dp[l][r]=1+dp[l+1][r];
            for(int i = l+1; i <= r; i++){
                if(v[l]==v[i]){
                    dp[l][r]=min({dp[l][r],(i==l+1 ? 0 : dp[l+1][i-1])+dp[i][r]});
                }
            }
        }
    }
    cout << dp[0][n-1];
}