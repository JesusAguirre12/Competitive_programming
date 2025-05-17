#include <bits/stdc++.h>
using namespace std;
int main(){
    int lo=1, hi=1e9;
    for(int i = 0; i < 30; i++){
        int mid = lo+(hi-lo)/2;
        cout <<"? "<< mid << endl;
        cout.flush(); 
        string k;
        cin >> k;
        if(k == "YES"){
            lo=mid+1; 
        }else{
            hi=mid; 
        }
    }
    cout<<"! "<<lo;
    cout.flush();
}