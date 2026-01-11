#include <bits/stdc++.h>
#define x first 
#define h second
using namespace std;
struct state{
    int l,r,q;
};
int main(){
    int n;
    cin>> n;
    vector<pair<int,int>> v(n);
    for(auto & [x,h] : v){
        cin >> x >> h;
    }
    vector<state> dp(n,{-1000000000,-1000000000,-1000000000});
    dp[0]={1,1,0};
    sort(v.begin(),v.end());
    for(int i = 1; i < n; i++){
        dp[i].q=max(dp[i-1].q,dp[i-1].l);
        if(v[i-1].x+v[i-1].h<v[i].x){
            dp[i].q=max(dp[i].q,dp[i-1].r);
        }
        
        if(v[i-1].x < v[i].x-v[i].h){
            dp[i].l=max(dp[i-1].l,dp[i-1].q);
            if(v[i-1].x+v[i-1].h<v[i].x-v[i].h){
                dp[i].l=max(dp[i].l,dp[i-1].r);
            }
            dp[i].l++;
        }
        dp[i].r=max(dp[i-1].l,dp[i-1].q);
        if(v[i-1].x+v[i-1].h<v[i].x){
            dp[i].r=max(dp[i].r,dp[i-1].r);
        }
        dp[i].r++;
    }
    cout << max({dp[n-1].l,dp[n-1].r,dp[n-1].q});
}