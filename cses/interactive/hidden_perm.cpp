#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> pos(n);
    auto cmp=[&](int i, int j){
        cout << '?' << ' ' <<  i << ' ' << j << endl;
        string ans;
        cin >> ans;
        if(ans=="YES"){
            return 1;
        }
        return 0;
    };
    vector<int> ord;
    ord.push_back(0);
    for(int i = 1; i < n; i++){
        int lo=0,hi=i;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(cmp(i+1,ord[mid]+1)){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        ord.insert(ord.begin()+lo,i);
    }
    cout << "! ";
    vector<int> ans(n);
    for(int i = 0; i< n; i++){
        ans[ord[i]]=i+1;
    }
    for(int i = 0; i< n; i++){
        cout << ans[i] << ' ';
    }
}