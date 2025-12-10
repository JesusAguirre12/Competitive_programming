#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first 
#define s second 
typedef tree<pair<int,int>, null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].f >> v[i].s;
    }
    indexed_set ans;
    indexed_set ans2;
    vector<int> order(n);
    vector<int> order2(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(),[&](int a, int b){
        if(v[a].f!=v[b].f){
            return v[a].f>v[b].f;
        }
        return v[a].s < v[b].s; 
    });
    iota(order2.begin(), order2.end(), 0);
    sort(order2.begin(), order2.end(),[&](int a, int b){
        if(v[a].s!=v[b].s){
            return v[a].s>v[b].s;
        }
        return v[a].f < v[b].f; 
    });
    ans.insert({v[order[0]].s,order[0]});
    ans2.insert({v[order2[0]].f,order2[0]});
    vector<int> vans(n,0), vans2(n,0);
    vans[order[0]]=0;
    vans2[order[0]]=0;
    for(int i = 1; i < n; i++){
        vans[order[i]]=ans.order_of_key({v[order[i]].s,n+1});
        ans.insert({v[order[i]].s,order[i]});
    }
    for(int i = 1; i < n; i++){ 
        vans2[order2[i]]=ans2.order_of_key({v[order2[i]].f,n+1});
        ans2.insert({v[order2[i]].f,order2[i]});
    }
    for(auto i : vans){
        cout << i << ' ';
    }
    cout << '\n';
    for(auto i : vans2){
        cout << i << ' ';
    }
}