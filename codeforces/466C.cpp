#include <bits/stdc++.h>
#define int long long 
using namespace std;
int32_t main(){
    int n;
    cin >> n;
    vector<int> pref(n+1,0);
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        pref[i]=pref[i-1]+v[i]; 
    }
    int tot=pref[n];
    if(tot%3!=0){
        cout << 0;
        return 0;
    }
    int cant=0;
    int ans=0;
    for(int i = 1; i < n; i++){
        if(pref[i]==2*tot/3){
            ans+=cant;
        }
        if(pref[i]==tot/3){
            cant++;
        }
    }
    cout << ans;
}