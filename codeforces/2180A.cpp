#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,a,b;
        cin>> n >> a >> b;
        cout << __gcd(b,n)*((n-1-a)/__gcd(b,n))+a << '\n';
    }
}