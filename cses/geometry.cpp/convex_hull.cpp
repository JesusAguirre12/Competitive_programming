#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pi pair<ll, ll>
 
int main() {
    int n;
    cin >> n;
    vector<pi> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
 
    sort(p.begin(), p.end(), [](pi &a, pi &b) {return a.first != b.first ? a.first < b.first : a.second > b.second;});
 
    auto cp = [](pi &a, pi &b, pi &c) { return (a.first - b.first) * (c.second - b.second) - (a.second - b.second) * (c.first - b.first); };
    auto cw = [&](pi &a, pi &b, pi &c) { return cp(a, b, c) > 0; };
 
    vector<pi> l, u;
    for (int i = 0; i < n; i++) {
        while (l.size() > 1 && cw(l[l.size()-2], l.back(), p[i])) l.pop_back();
        l.push_back(p[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        while (u.size() > 1 && cw(u[u.size()-2], u.back(), p[i])) u.pop_back();
        u.push_back(p[i]);
    }
 
    set<pi> s;
    vector<pi> res;
    for (auto &x : l) if (!s.count(x)) { res.push_back(x); s.insert(x); }
    for (auto &x : u) if (!s.count(x)) { res.push_back(x); s.insert(x); }
 
    cout << res.size() << "\n";
    for (auto &x : res) cout << x.first << " " << x.second << "\n";
}