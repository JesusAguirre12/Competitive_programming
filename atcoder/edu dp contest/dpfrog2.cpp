#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;;
    vector<int> v(n);
    for(auto &i: v){
        cin >> i;
    }
    vector<int> dp(n,1e9);
    dp[0]=0;
    dp[1]=abs(v[1]-v[0]);
    for(int i = 2; i < n; i++){
        for(int j = 1; j <= k && i-j >= 0; j++){
            dp[i]=min(dp[i],dp[i-j]+abs(v[i]-v[i-j]));
        }
    }
    cout << dp[n-1];
}