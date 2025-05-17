#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long 
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
struct point{
    int x, y;
};
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<point, point>> ver; 
    vector<pair<point, point>> hor;
    for (int i = 0; i < n; i++) {
        point a, b;
        cin >> a.x >> a.y >> b.x >> b.y;
        if (a.x == b.x) {
            if (a.y > b.y) {
                swap(a, b);
            }
            ver.push_back({a, b});
        } else {
            if (a.x > b.x) {
                swap(a, b);
            }
            hor.push_back({a, b});
        }
    }
    sort(ver.begin(), ver.end(), [&](pair<point, point> a, pair<point, point> b) {
        return a.first.y < b.first.y;
    });
    sort(hor.begin(), hor.end(), [&](pair<point, point> a, pair<point, point> b){
        return a.first.y < b.first.y;
    });
    vector<pair<point, point>> ver2 = ver;
    sort(ver2.begin(), ver2.end(), [&](pair<point, point> a, pair<point, point> b){
        return a.second.y < b.second.y;
    });
    indexed_set active;
    int i1 = 0;   
    int i2 = 0;   
    int ans = 0;
    for(auto &[a, b] : hor) {
        int y = a.y; 
        if(b.x-a.x<=1)continue;
        while(i1<ver.size()&&ver[i1].first.y<y){
            if(ver[i1].second.y>y){
                active.insert(ver[i1].first.x);
            }
            i1++;
        }
        while(i2<ver2.size() && ver2[i2].second.y<=y){
            int x_val = ver2[i2].first.x;
            auto it = active.find(x_val);
            if(it != active.end())
                active.erase(it);
            i2++;
        }
        ans += active.order_of_key(b.x)-active.order_of_key(a.x+1);
    }
    cout << ans << "\n";
    return 0;
}