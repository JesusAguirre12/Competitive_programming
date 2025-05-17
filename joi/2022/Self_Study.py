#54 pts
import sys
n, m=map(int, input().split())
a=list(map(int, input().split()))
b=list(map(int, input().split()))
lo=0
hi=max(a)*m
while lo <= hi:
    mid=(lo+hi)>>1
    need=0
    for i in range(n):
        need+=(mid+a[i])//a[i]
        if need>n*m:
            break
    if need <= n*m:
        lo = mid+1
    else:
        hi = mid-1

print(lo)
#CPP
"""
10 pts
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++){cin >> a[i];}
    for(int i = 0; i < n; i++){cin >> b[i];}
    if(m == 1){
        ll ans=LLONG_MAX;
        for(int i = 0; i < n; i++){
            ans=min(ans,max(a[i],b[i]));
        }
        cout<<ans<< "\n";
        return 0;
    }
    return 0;
}
"""