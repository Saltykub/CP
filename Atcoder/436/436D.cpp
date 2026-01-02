#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
using namespace std;
const int N = 1e3+10;
bool CASE = false;
char tab[N][N];
ll dis[N][N];
void solve (){
    int n,m;
    cin >> n >> m;
    vector<pii> warp[26];
    bool go[26];
    for(int i = 0; i < 26; i++) go[i] = false;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> tab[i][j];
            dis[i][j] = INT_MAX;
            if(isalpha(tab[i][j])){
                int c = tab[i][j]-'a';
                warp[c].pb({i,j});
            }
        }
    }
    
    priority_queue<piii,vector<piii>,greater<piii>> pq;
    pii d[4] = {{0,1},{0,-1},{1,0},{-1,0}};
    pq.push({0,{0,0}});
    dis[0][0] = 0;
    while(!pq.empty()){
        auto [cur,xy] = pq.top();
        auto [x,y] = xy;
        pq.pop();
        if(dis[x][y] < cur) continue;
        for(int i = 0; i < 4; i++){
            int xx = x+d[i].st, yy = y+d[i].nd;
            if(xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
            if(tab[xx][yy] == '#') continue;
            if(dis[xx][yy] > 1+cur){
                dis[xx][yy] = 1+cur;
                pq.push({dis[xx][yy],{xx,yy}});
            }
        }
        int c = tab[x][y]-'a';
        if(isalpha(tab[x][y]) && !go[c]){
            //cout << c;
            for(auto [xx,yy]:warp[c]){
                if(dis[xx][yy] > 1+cur){
                    dis[xx][yy] = 1+cur;
                    pq.push({dis[xx][yy],{xx,yy}});
                }
            }
        }
        go[c] = true;
    }
    if(dis[n-1][m-1] != INT_MAX) cout << dis[n-1][m-1];
    else cout << -1;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}