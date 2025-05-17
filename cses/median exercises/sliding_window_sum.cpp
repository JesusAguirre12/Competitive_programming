#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    int n, k,x,a,b,c,tot,sum=0;
    cin >> n >> k >> x >> a >> b >> c;
    int prev = x;
    int last;
    sum+=x;
    for(int i = 1; i < k; i++){
        sum+=(a*prev+b)%c;
        prev=(a*prev+b)%c;
    }
    last=prev;
    prev=x;
    int accum=sum;
    for(int i = k; i < n; i++){
        last=(a*last+b)%c;
        accum+=last;
        accum-=prev;
        prev=(a*prev+b)%c;
        sum^=accum;
    }
    cout << sum << '\n';
}
