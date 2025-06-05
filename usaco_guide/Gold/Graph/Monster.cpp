#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
    int n,m;
    cin >> n >> m;
    vector<vector<char>> tab(n,vector<char>(m));
    queue<pii> q, q1;
    vector<vector<int>>  dis(n,vector<int>(m,INT_MAX));
    vector<vector<int>> disM(dis);
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
        cin >> tab[i][j];
        if(tab[i][j] == 'A') q.push({i,j}),dis[i][j] = 0;
        if(tab[i][j] == 'M') q1.push({i,j}),disM[i][j] = 0;
    }
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    string p = "UDLR";
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x+dx[i], ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(tab[nx][ny] == '#' || dis[nx][ny] != INT_MAX) continue; 
            dis[nx][ny] = dis[x][y] + 1;
            q.push({nx,ny});
        }
    }

    while(!q1.empty()){
        auto [x,y] = q1.front();
        if(disM[x][y] <= dis[x][y]) dis[x][y] = INT_MAX;
        q1.pop();
        for(int i = 0; i < 4; i++){
            int nx = x+dx[i], ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(tab[nx][ny] == '#' || disM[nx][ny] != INT_MAX) continue; 
            disM[nx][ny] = disM[x][y] + 1;
            q1.push({nx,ny});
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 || i == n-1 || j == 0 || j ==  m-1){
                if(dis[i][j] != INT_MAX){
                    int tx = i, ty = j;
                    cout << "YES\n";
                    cout << dis[tx][ty] << "\n";
                    int cur = dis[tx][ty];
                    vector<char> path;
                    if(cur == 0) return;
                    while(true){
                        for(int k = 0; k < 4; k++){
                            int nx = tx+dx[k], ny = ty + dy[k];
                            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                            if(dis[nx][ny] == cur-1){
                                path.pb(p[k]);
                                tx = nx;
                                ty = ny;
                                break;
                            }
                        }
                        cur--;
                        if(cur == 0) break;
                    }
                    reverse(path.begin(),path.end());
                    for(auto u:path) cout << u;
                    return;
                }
            }
        }
    }
    cout << "NO";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}