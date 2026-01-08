#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> pref1, pref2;
vector<vector<bool>> p,f;
void open(string name = ""){
    	cin.tie(0)->sync_with_stdio(0); 
    	freopen((name + ".in").c_str(), "r", stdin);
    	freopen((name + ".out").c_str(), "w", stdout);
}
int main(){
    open("frutales");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    pref1.assign(n+1,vector<int>(m+1,0));
    pref2.assign(n+1,vector<int>(m+1,0));
    f.assign(n+1,vector<bool>(m+1,0));
    p.assign(n+1,vector<bool>(m+1,0));
    int n1,m1;
    cin >> n1 >> m1;
    for(int i = 0; i < n1; i++){
        int x,y;
        cin >> x >> y;
        p[x][y]=1;
    }
    for(int i = 0; i < m1; i++){
        int x,y;
        cin >> x >> y;
        f[x][y]=1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            pref1[i][j]=pref1[i-1][j]+pref1[i][j-1]-pref1[i-1][j-1]+f[i][j];
            pref2[i][j]=pref2[i-1][j]+pref2[i][j-1]-pref2[i-1][j-1]+p[i][j];
        }
    }
    vector<vector<int>> dp(n+2,vector<int> (m+2,0));
    for(int i = n; i > 0; i--){
        for(int j = m; j > 0; j--){
            if(p[i][j]){
                dp[i][j]=0;
                continue;
            }else{
                if(i==n && j==m){
                    dp[i][j]=1;
                    continue;
                }
                dp[i][j]=1+min({dp[i+1][j],dp[i+1][j+1],dp[i][j+1]});
            }
        }
    }
    int x,y;
    int sz=-1, ans=-1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int l = dp[i][j];
            int c=pref1[i+l-1][j+l-1]-pref1[i+l-1][j-1]-pref1[i-1][j+l-1]+pref1[i-1][j-1];
            if(c>ans || c==ans && l<sz){
                ans=c;
                sz=l;
                x=i;
                y=j;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int lo=1,hi=dp[i][j];
            while(lo<=hi){
                int l=(lo+hi)>>1;
                int c=pref1[i+l-1][j+l-1]-pref1[i+l-1][j-1]-pref1[i-1][j+l-1]+pref1[i-1][j-1];
                if(c>=ans){
                    hi=l-1;
                    if(l<sz){
                        x=i;
                        y=j;
                        sz=l;
                        ans=c;
                    }
                }else{
                    lo=l+1;
                }
            }
        }
    }
    cout << x-1 << ' ' << y-1 << '\n' << sz << '\n' << ans << '\n';
}
