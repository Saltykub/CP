#include<bits/stdc++.h>
#define ll long long 
#define pii pair<ll,ll>
#define st first 
#define nd second 
#define pb push_back
using namespace std;
const int N = 1e3+10;
char tab[N][N];
bool vis[N][N];
pii go[4] = {{1,0},{-1,0},{0,1},{0,-1}};
void dfs(int x,int y, int n,int m){
    if(vis[x][y])return;
    vis[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x+go[i].st, ny = y+go[i].nd;
        if(nx > n || nx <1 || ny > m || ny < 1)continue;
        if(tab[nx][ny] == '#')continue;
        dfs(nx,ny,n,m);
    }
}
int main(){
    int ans = 0;
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)for(int j = 1; j <= m; j++)cin>>tab[i][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!vis[i][j] && tab[i][j] == '.'){
                ans++;
                dfs(i,j,n,m);
            }
        }
    }
    cout << ans;
}