#include <bits/stdc++.h>
using namespace std; 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        vector<bool> vis(n+1,0);
        for(auto i : v){
            if(i<=n){
                vis[i]=1;
            }
        }
        int ans=n+1;
        for(int i = 0; i <= n; i++){
            if(!vis[i]){
                ans=i;
                break;
            }
        }
        cout << min(ans,k-1) << '\n';
    }
}