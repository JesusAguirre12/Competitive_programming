#include <bits/stdc++.h>
#define int long long 
using namespace std;
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int x;
        cin>> x;
        for(int i = 0; i < n-1; i++){
            int k;
            cin >> k;
            x^=k;
        }
        if(x){
            cout << "first\n";
        }else{
            cout << "second\n";
        }
    }
}