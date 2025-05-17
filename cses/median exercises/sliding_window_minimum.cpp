#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    int n, k,x,a,b,c,tot,sum=0;
    cin >> n >> k >> x >> a >> b >> c;
    deque<pair<int, int>> dq;
    int ans = 0;
    int vv = x;
    for(int i = 0; i < n; i++){
        while(!dq.empty()&&dq.back().first >= vv){
            dq.pop_back();
        }
        dq.emplace_back(vv, i);
        while(!dq.empty() && dq.front().second<=i-k){
            dq.pop_front();
        }
        if(i >= k - 1){
            ans^=dq.front().first;
        }
        vv = (a*vv+b)%c;
    }
    cout << ans;
    return 0;
}