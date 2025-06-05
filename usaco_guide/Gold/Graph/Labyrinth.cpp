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
    queue<pii> q;
    vector<vector<int>>  dis(n,vector<int>(m,INT_MAX));
    int tx = 0, ty = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
        cin >> tab[i][j];
        if(tab[i][j] == 'A') q.push({i,j}),dis[i][j] = 0;
        if(tab[i][j] == 'B') tx = i, ty = j;
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
    if(dis[tx][ty] == INT_MAX) {
        cout << "NO";
    }
    else {
        cout << "YES\n";
        cout << dis[tx][ty] << "\n";
        int cur = dis[tx][ty];
        vector<char> path;
        while(true){
            for(int i = 0; i < 4; i++){
                int nx = tx+dx[i], ny = ty + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(dis[nx][ny] == cur-1){
                    path.pb(p[i]);
                    tx = nx;
                    ty = ny;
                    break;
                }
            }
            cur--;
            if(cur == 0) break;
        }
        // for(auto u:dis){
        //     for(auto v:u) {
        //         if(v == INT_MAX) cout << -1;
        //         else cout << v;
        //         cout << " ";
        //     }
        //     cout << "\n";
        // }
        reverse(path.begin(),path.end());
        for(auto u:path) cout << u;
    }
    

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}