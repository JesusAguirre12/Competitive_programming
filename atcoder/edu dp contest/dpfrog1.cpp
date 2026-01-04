#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(n,0);
    for(auto & i : v){
        cin >> i;
    }
    vector<int> dp(n,0);
    dp[0]=0;
    dp[1]=abs(v[0]-v[1]);
    for(int i = 2; i < n; i++){
        dp[i]=min(dp[i-1]+abs(v[i]-v[i-1]),dp[i-2]+abs(v[i]-v[i-2]));
    }
    cout << dp[n-1];
}