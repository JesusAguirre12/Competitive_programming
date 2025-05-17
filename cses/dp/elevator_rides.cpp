#include <bits/stdc++.h>
#define f first
#define s second
#define ll long long
using namespace std;
const int INF = INT_MAX;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto&i:v){cin >> i;}
    vector<pair<ll,ll>> dp((1<<n)+1, {INF, INF});
    dp[0] = {0,0};
    for(int m = 0; m < (1<<n); m++){
        for(int j = 0; j < n; j++){
            if(!(m&(1<<j))){
                int nm = m|(1<<j);
                pair<ll,ll> np = {dp[m].f+v[j], dp[m].s};
                if(np.f>k){
                    np.s++;
                    np.f=v[j];
                }
                if(np.s==dp[nm].s&&np.f<dp[nm].f){
                    dp[nm]=np;
                }else if(np.s<dp[nm].s){
                    dp[nm]=np;
                }
            }
        }
    }
    cout << dp[(1<<n)-1].s+(dp[(1<<n)-1].f > 0LL ? 1LL : 0LL);
}