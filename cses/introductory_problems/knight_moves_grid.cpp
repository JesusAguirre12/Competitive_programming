#include <bits/stdc++.h>
#define f first
#define s second 
using namespace std;
vector<int> dx = {-1,-1, 2,-2,1, 1, 2, -2}, 
            dy = {2 ,-2,-1,-1,2,-2, 1, 1};
            
bool is_valid(int x, int y, int n){
    if(x>=n||y>=n||x<0||y<0){
        return 0;
    }
    return 1;
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> dist(n, vector<int>(n,1e9));
    vector<vector<bool>> visited(n,vector<bool>(n,0));
    dist[0][0]=0;
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        auto p=q.front();q.pop();
        int x=p.f, y=p.s;
        if(visited[x][y]){
            continue;
        }
        visited[x][y]=1;
        for(int i = 0; i < 8; i++){
            int nx=x+dx[i], ny=y+dy[i];
            if(is_valid(nx,ny,n)){
                if(visited[nx][ny]){
                    continue;
                }
                dist[nx][ny]=dist[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}
