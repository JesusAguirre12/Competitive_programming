#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
long long solve(long long n){
    long long ans = 0LL;
    long long d = 1LL;
    while (d <= n) {
        long long q = n/d;
        long long dd = n/q+1LL;
        long long c = (((dd-d) % MOD) * (((d + dd - 1) % MOD)) % MOD) * 500000004%MOD;
        ans += (c % MOD) * (q % MOD) % MOD;
        ans %= MOD;
        d = dd;
    }
    return ans % MOD;
}
int main() {
    long long n;
    cin >> n;
    cout << solve(n);
    return 0;
}