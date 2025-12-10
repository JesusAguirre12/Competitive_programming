#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first 
#define s second 
typedef tree<pair<int,int>, null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,a,b;
        cin >> n >> a >> b;
        if(a==0 && b==0){
            cout << "YES\n";
            for(int i = 0; i < n; i++){
                cout << i+1 << ' ';
            }
            cout << '\n';
            for(int i = 0; i < n; i++){
                cout << i+1 << ' ';
            }
            cout << '\n';
        }else if(a+b>n || a==0 || b==0){
            cout << "NO\n";
        }else{
            cout << "YES\n";
            for(int i = 0; i < n; i++){
                cout << i+1 << ' ';
            }
            cout << '\n';
            for(int i = 0; i < n-a-b; i++){
                cout << i+1 << ' ';
            }
            for(int i = n-b; i < n; i++){
                cout << i+1 << ' ';
            }
            for(int i = n-a-b; i < n-b; i++){
                cout << i+1 << ' ';
            }
            cout << '\n';
        }
        
    }
   
}