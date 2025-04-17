//100 pts
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
int X[MAXN], tree[4*MAXN];
vector<int> v;
void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = X[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(2*node+1, l, mid);
    build(2*node+2, mid+1, r);
    tree[node] = min(tree[2*node+1], tree[2*node+2]);
}

int query(int node, int tl, int tr, int l, int r) {
    if (l > r || r < tl || l > tr) return INT_MAX;
    if (l <= tl && tr <= r) return tree[node];
    int mid = (tl + tr) >> 1;
    return min(
        query(2*node+1, tl, mid, l, r),
        query(2*node+2, mid+1, tr, l, r)
    );
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x, q;
    cin >> n >> x;
    v.resize(n);
    for (int i = 0; i < n; i++){cin >> v[i];}
    for (int i = 0; i < n; i++) {
        int c=int(upper_bound(v.begin(), v.end(), x-v[i])-v.begin())-1;
        X[i] = c+i;
    }
    build(0, 0, n-1);
    string ans = "";
    cin >> q;
    while (q--) {
        long long l, r;
        cin >> l >> r;
        l--;r--;
        ans.push_back(query(0, 0, n - 1, l, (l+r-((r-l+1LL)%2LL))/2LL) >= (l+r-((r-l-1LL)%2LL)) ? '1' : '0');
    }
    cout << ans << '\n';
}