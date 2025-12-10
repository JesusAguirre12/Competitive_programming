#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first 
#define s second 
typedef tree<pair<int,int>, null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
void open(string name = "") {
	cin.tie(0)->sync_with_stdio(0); 
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}
int main(){
    open("sumo");
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].f >> v[i].s;
    }
    indexed_set ans;
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(),[&](int a, int b){
        if(v[a].f!=v[b].f){
            return v[a].f<v[b].f;
        }
        return v[a].s < v[b].s; 
    });
    ans.insert({v[order[0]].s,order[0]});
    vector<int> vans(n,0);
    vans[order[0]]=0;
    for(int i = 1; i < n; i++){
        vans[order[i]]=ans.order_of_key({v[order[i]].s,n+1});
        ans.insert({v[order[i]].s,order[i]});
    }
    for(auto i : vans){
        cout << i << '\n';
    }
}