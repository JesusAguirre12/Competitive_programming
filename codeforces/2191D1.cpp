#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin>> s;
        vector<int> pc(n+1,0), pa(n+1,0),last(n+1);
        int idx=-1;
        for(int i = n-1; i >= 0; i--){
            last[i]=idx;
            if(s[i]!=')'){
                idx=i;
            }
        }
        for(int i = 0; i < n; i++){
            if(s[i]==')'){
                pc[i+1]=pc[i]+1;
                pa[i+1]=pa[i];
            }else{
                pa[i+1]=pa[i]+1;
                pc[i+1]=pc[i];
            }
        }
        int ans=-1;
        for(int i = 0; i < n; i++){
            if(s[i]=='('){
                continue;
            }
            if(last[i]==-1){
                continue;
            }
            int curr=pa[i]-pc[i];
            int sa=pa[n]-pa[last[i]+1], sc=pc[n]-pc[last[i]+1];
            if(sc >= curr+1){
                int mx=min({sc-curr-1,sa});
                if(mx>-1){
                    int cans=i+curr+((mx+1)<<1);
                    if(cans>1){
                        ans=max(cans,ans);
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}