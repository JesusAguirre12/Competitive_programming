#include <bits/stdc++.h>
#define int long long 
using namespace std;
int k;
vector<int> v;
void build(vector<int>& t, int tl, int tr){
    vector<int> dp(1<<(tr-tl));
    dp[0<<0]=0;
    for(int m = 0; m < 1<<(tr-tl); m++){
        int sum=0;
        for(int j = 0; j<(tr-tl); j++){
            if(m&(1<<j)){
                sum+=v[tl+j];
            }
        }
        t.push_back(sum);
    }
}
int32_t main(){
    int n, k,ans=0;
    cin >> n >> k;
    vector<int> l, r;
    v.resize(n);
    for(auto&i:v){
        cin >> i;
    }
    build(l,0,n/2);
    build(r,n/2,n);
    sort(r.begin(),r.end());
    for(auto&i:l){
        ans+=upper_bound(r.begin(),r.end(),k-i)-lower_bound(r.begin(),r.end(),k-i);
    }
    cout << ans;
}