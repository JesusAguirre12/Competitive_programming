//100 pts
#include <bits/stdc++.h>
using namespace std;
int tablero(string &pieza, string &salida, string &llegada, vector<string> &escaques) {
    auto coordToIndex = [&](const string &pos) -> pair<int,int>{
        int col = pos[0]-'a'; 
        int row = 8-(pos[1]-'0'); 
        return {row, col};
    };
    pair<int,int> start = coordToIndex(salida);
    pair<int,int> target = coordToIndex(llegada);
    if(start==target)return 0;  
    vector<vector<int>> dist(8, vector<int>(8, -1));
    queue<pair<int,int>> q;
    dist[start.first][start.second] = 0;
    q.push(start);
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        int curD = dist[cur.first][cur.second];
        if(cur == target)
            return curD;
        if(pieza == "rey"){
            int dr[8] = {1, -1, 0, 0, 1, 1, -1, -1};
            int dc[8] = {0, 0, 1, -1, 1, -1, 1, -1};
            for (int i = 0; i < 8; i++){
                int nr = cur.first+dr[i];
                int nc = cur.second+dc[i];
                if(nr >= 0 && nr < 8 && nc >= 0 && nc < 8 && escaques[nr][nc] == 'L' && dist[nr][nc] == -1){
                    dist[nr][nc] = curD+1;
                    q.push({nr, nc});
                }
            }
        }
        else if(pieza == "caballo"){
            int dr[8] = {2, 2, -2, -2, 1, 1, -1, -1};
            int dc[8] = {1, -1, 1, -1, 2, -2, 2, -2};
            for (int i = 0; i < 8; i++){
                int nr = cur.first+dr[i];
                int nc = cur.second+dc[i];
                if(nr >= 0 && nr < 8 && nc >= 0 && nc < 8 && escaques[nr][nc] == 'L' && dist[nr][nc] == -1){
                    dist[nr][nc] = curD+1;
                    q.push({nr, nc});
                }
            }
        }
        else if(pieza == "torre"){
            int dr[4] = {1, -1, 0, 0};
            int dc[4] = {0, 0, 1, -1};
            for (int i = 0; i < 4; i++){
                int nr = cur.first, nc = cur.second;
                while (true) {
                    nr += dr[i];
                    nc += dc[i];
                    if(nr < 0 || nr >= 8 || nc < 0 || nc >= 8)
                        break;
                    if(escaques[nr][nc] == 'X')
                        break;
                    if(dist[nr][nc] != -1)
                        continue;
                    dist[nr][nc] = curD+1;
                    q.push({nr, nc});
                }
            }
        }
        else if(pieza == "alfil"){
            int dr[4] = {1, 1, -1, -1};
            int dc[4] = {1, -1, 1, -1};
            for (int i = 0; i < 4; i++){
                int nr = cur.first, nc = cur.second;
                while (true) {
                    nr += dr[i];
                    nc += dc[i];
                    if(nr < 0 || nr >= 8 || nc < 0 || nc >= 8)
                        break;
                    if(escaques[nr][nc] == 'X')
                        break;
                    if(dist[nr][nc] != -1)
                        continue;
                    dist[nr][nc] = curD+1;
                    q.push({nr, nc});
                }
            }
        }
        else if(pieza == "dama"){
            int dr[8] = {1, -1, 0, 0, 1, 1, -1, -1};
            int dc[8] = {0, 0, 1, -1, 1, -1, 1, -1};
            for (int i = 0; i < 8; i++){
                int nr = cur.first, nc = cur.second;
                while (true) {
                    nr += dr[i];
                    nc += dc[i];
                    if(nr < 0 || nr >= 8 || nc < 0 || nc >= 8)
                        break;
                    if(escaques[nr][nc] == 'X')
                        break;
                    if(dist[nr][nc] != -1)
                        continue;
                    dist[nr][nc] = curD+1;
                    q.push({nr, nc});
                }
            }
        }
    }
    return -1;
}
