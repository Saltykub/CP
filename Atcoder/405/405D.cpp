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
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
        cin >> tab[i][j];
        if(tab[i][j] == 'E') q.push({i,j});
    }
    pii d[4] = {{1,0},{-1,0},{0,1},{0,-1}};
    char val[4] = {'^','v','<','>'};
    while(!q.empty()){
        auto[x,y] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + d[i].st, ny = y + d[i].nd;
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(tab[nx][ny] != '.') continue;
            tab[nx][ny] = val[i];
            q.push({nx,ny});
        }
    }
    for(auto t:tab){
        for(auto u:t) cout << u;
        cout << "\n";
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