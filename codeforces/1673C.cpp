#include <bits/stdc++.h>
#define int long long 
using namespace std; 
const int mod = 1e9+7;
int32_t main(){
    vector<int> pal;
    for(int i = 1; i < 40000; i++){
        string s=to_string(i);
        bool ok=1;
        for(int j = 0; j <= s.length()/2; j++){
            if(s[j]!=s[s.length()-j-1]){
                ok=0;
                break;
            }
        }
        if(ok){
            pal.push_back(i);
        }
    }
    vector<int> dp(40001,0);
    dp[0]=1;
    for(auto p : pal){
        for(int i = p; i <= 40000; i++){
            dp[i]+=dp[i-p];
            dp[i]%=mod;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
}