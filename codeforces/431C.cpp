#include <bits/stdc++.h>
#define int long long 
using namespace std;
int32_t main(){
    int n,k,d;
    cin >> n>> k >> d;
    vector<int> dpg(n+1,0),dpb(n+1,0);
    dpg[0]=1;
    dpb[0]=1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(i-j>-1){
                dpg[i]+=dpg[i-j];
                dpg[i]%=(int)(1e9+7);
            }
        }
        for(int j = 1; j < d; j++){
            if(i-j>-1){
                dpb[i]+=dpb[i-j];
                dpb[i]%=(int)(1e9+7);
            }
        }
    }
    cout << (dpg[n]-dpb[n]+(int)(1e9+7))%(int)(1e9+7) << '\n';
}