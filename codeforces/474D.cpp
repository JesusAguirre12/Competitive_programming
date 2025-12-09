#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int mod=1e9+7LL;
int32_t main(){
    int t, k;
    cin >> t >> k;
    vector<int> dp(1e5+5,0);
    for(int i = 0; i < k; i++){
        dp[i]=1LL;
    }
    dp[k]=2LL;
    for(int i = k; i <= 1e5; i++){
        dp[i]=dp[i-1]%mod+dp[i-k]%mod;
        dp[i]%=mod;
    }
    vector<int> pref(1e5+5,0);
    pref[0]=dp[0];
    for(int i = 1; i <= 1e5; i++){
        pref[i]=dp[i]+pref[i-1]%mod;
        pref[i]%=mod;
    }
    while(t--){
        int a,b;
        cin >> a >> b;
        cout << (pref[b]-pref[a-1LL]+mod)%mod << '\n';
    }
}