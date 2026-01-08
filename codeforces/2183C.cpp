#include <bits/stdc++.h>
#define int long long 
using namespace std; 
int32_t main(){
    int t;
    cin >> t;
    while(t--){ 
        int n,k,m;
        cin >> n >> m >> k;
        int ans=0;
        for(int i = 0; i < k; i++){
            if(m>=(i<<1)-1){
                int r=min({n-k,i,m+1-(i<<1)});
                if(r>=0){
                    ans=max(ans,i+r);
                }
            }
        }
        for(int i = 0; i < n-k+1; i++){
            if(m>=(i<<1)-1){
                int l=min({k-1,i,m+1-(i<<1)});
                if(l>=0){
                    ans=max(ans,i+l);
                }
            }
        }
        cout << min(ans+1,n) << '\n';
    }
}