#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("mesadas.in", "r", stdin);
    freopen("mesadas.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v[i] = {max(x, y), min(x,y)};
    }
    sort(v.begin(), v.end());
    set<int> ans;
    for(auto i : v){
        auto it = ans.lower_bound(-i.second);
        if(it == ans.end()){ans.insert(-i.second);}
        else{
            ans.erase(it);
            ans.insert(-i.second);
        }
    }
    cout << ans.size() << endl;
}