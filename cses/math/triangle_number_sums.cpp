#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    int accum=1;
    int idx=2;
    vector<int> tot;
    while(accum<=1e12){
        tot.push_back(accum);
        accum+=idx;
        idx++;
    }
    tot.push_back(1e18);
    while(t--){
        int k;
        cin >> k;
        int sq=sqrt(1+(k<<3));
        if(sq*sq==1+(k<<3)){
            cout<<1<<'\n';
            continue;
        }
        int ans=0;
        int j = lower_bound(tot.begin(),tot.end(),k)-tot.begin();
        int i = 0;
        while(i<=j){
            if(tot[i]+tot[j]==k){
                cout << 2 << '\n';
                goto ex;
            }else if(tot[i]+tot[j]<k){
                i++;
            }else{
                j--;
            }
        }
        cout << 3 << '\n';
        ex:;
    }
}