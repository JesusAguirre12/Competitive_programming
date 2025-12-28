#include <bits/stdc++.h>
#define int long long 
#define f first
#define s second
using namespace std;
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int tot=0;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin>> v[i];
            if(i){
                tot+=abs(v[i-1]-v[i]);
            }
        }
        int ans=tot;
        for(int i = 1; i < n-1; i++){
            ans=min(ans,tot-abs(v[i-1]-v[i])-abs(v[i]-v[i+1])+abs(v[i-1]-v[i+1]));
        }
        ans=min({ans,tot-abs(v[0]-v[1]),tot-abs(v[n-2]-v[n-1])});
        cout << ans << '\n';
    }
}