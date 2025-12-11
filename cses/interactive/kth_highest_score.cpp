#include <bits/stdc++.h>
using namespace std;
int ask(int i, char c){
    if(i <= 0){
        return 1e9+5; 
    }
    cout << c << ' ' << i << endl;
    int x;
    cin >> x;
    return x;
}
int main(){
    int n, k;
    cin >> n >> k;
    int lo=max(0, k-n);
    int hi=min(k,n);
    while(lo<=hi){
        int i = lo+(hi-lo)/2;   
        int j = k-i;          
        int maxf  = ask(i,'F');
        int minf = (i+1<=n?ask(i+1,'F'): -1);  
        int maxs  = ask(j,'S');
        int mins = (j+1<=n?ask(j+1,'S'): -1);  
        if(maxf >= mins && maxs >= minf){
            int ans;
            if(i == 0){
                ans=maxs; 
            }else if(j==0){
                ans=maxf; 
            }else{
                ans=min(maxf, maxs);
            }
            cout << "! " << ans << endl;
            break;
        }
        if(maxf < mins){
            hi=i-1;
        }else{
            lo=i+1;
        }
    }
}
