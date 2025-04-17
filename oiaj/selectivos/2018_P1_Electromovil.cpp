//100 pts
#include <bits/stdc++.h>
using namespace std;
vector<int> electromovil(int E, vector<int> ubicacion, vector<int> autonomia)
{
    int n = autonomia.size();
    vector<pair<int, int>> v(n);
    vector<int> x(0);
    for(int i = 0; i < n; i++){
        int x = ubicacion[i], y = autonomia[i];
        v[i] = {x,y};
    }
    int j = 1, max_cur = v[0].second, maxprev = v[0].second; 
    int curest = 0;
    vector<int> ans;
    while(j < n){
        if(v[j].first <= maxprev){
            if(v[j].first+v[j].second >= max_cur){
                max_cur = v[j].first+v[j].second;
                curest = v[j].first;
            }
        }else{
            maxprev = max_cur;
            ans.push_back(curest);
            if(v[j].first <= max_cur){
                max_cur = v[j].first+v[j].second;
                curest = v[j].first;
            }
        }
        if(j == n-1 and maxprev >= v[j].first){
            ans.push_back(v[j].first);
            return ans;
        }
        j++;
    }
    return x;
}