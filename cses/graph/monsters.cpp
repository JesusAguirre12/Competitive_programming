#include <bits/stdc++.h>
#define ll long long 
#define s second
#define f first
using namespace std;
const ll inf = 1e9+5;
int n, m;
vector<int> dx = {-1,1,0,0}, 
            dy = {0,0,-1,1};
            
bool is_valid(int x, int y){
    if(x>=n||y>=m||x<0||y<0){
        return 0;
    }
    return 1;
}
char convert(int x, int y, int nx, int ny){
    if(nx<x){
        return 'U';
    }if(nx>x){
        return 'D';
    }if(ny>y){
        return 'R';
    }
    return 'L';
}
int main(){
    cin >> n >> m;
    vector<string> grid(n);
    priority_queue<pair<ll,pair<int,int>>, vector<pair<ll,pair<int,int>>>, greater<pair<ll,pair<int,int>>>> pq;
    vector<vector<bool>> visited(n,vector<bool>(m,0));
    vector<vector<ll>> dist(n,vector<ll>(m,inf));
    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m, {0,0}));
    int sx =-1, sy=-1;
    for(int i = 0; i < n; i++){
        cin >> grid[i];
        for(int j = 0; j < m; j++){
            if(grid[i][j]=='M'){
                pq.push({0,{i,j}});
                dist[i][j]=0;
            }
            if(grid[i][j]=='A'){
                sx=i;sy=j;
            }
        }
    }
    if(sx==0||sx==n-1||sy==0||sy==m-1){
        cout << "YES\n"<<0;
        return 0;
    }
    while(!pq.empty()){
        int x = pq.top().s.f;
        int y = pq.top().s.s;
        pq.pop();
        for(int i = 0; i < 4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(is_valid(nx,ny) and grid[nx][ny]!='#'){
                if(dist[nx][ny]>dist[x][y]+1){
                    dist[nx][ny]=dist[x][y]+1;
                    pq.push({dist[nx][ny],{nx,ny}});
                }
            }
        }
    }
    int fx = -1, fy = -1;
    bool found=0;
    pq.push({0,{sx,sy}});
    while(!pq.empty()){
        int x = pq.top().s.f;
        int y = pq.top().s.s;
        int curr = pq.top().f+1;
        pq.pop();
        if(visited[x][y]){
            continue;
        }
        visited[x][y]=1;
        for(int i = 0; i < 4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(visited[nx][ny]){
                continue;
            }
            if(is_valid(nx,ny) and grid[nx][ny]!='#'){
                parent[nx][ny]={x,y};
                if(dist[nx][ny]>curr){
                    if(nx==n-1 or ny==m-1 or nx==0 or ny==0){
                        cout << "YES\n";
                        fx=nx;
                        fy=ny;
                        found=1;
                        break;
                    }
                    pq.push({curr,{nx,ny}});
                }
            }
        }
        if(found){
            break;
        }
    }
    if(!found){
        cout << "NO\n";
        return 0;
    }
    string ans = "";
    int xx = fx, yy = fy;
    while(1){
        pair<int,int> p = parent[xx][yy];
        ans.push_back(convert(p.f, p.s, xx, yy));
        xx=p.f;yy=p.s;
        //cout << xx << ' ' << yy << '\n';
        if(xx==sx&&yy==sy){
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    cout <<ans.size() << '\n'<< ans << '\n';
}