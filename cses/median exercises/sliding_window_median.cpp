#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;
int main() {
    int n, k;
    cin >> n >> k;
    indexed_multiset s;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    for(int i = 0; i < k; i++){
        s.insert(v[i]);
    }
    cout << *s.find_by_order((k+1)/2-1) << ' ';
    for(int i = k; i < n; i++){
        auto it = s.upper_bound(v[i - k]);
        if(*it == v[i-k]){
            s.erase(it);
        }else if (it != s.begin()) {
            it--; 
            s.erase(it);
        }
        s.insert(v[i]);
        cout << *s.find_by_order((k+1)/2-1) << ' ';
    }
    return 0;
}