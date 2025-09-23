#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e3+10;
char tab[N][N];
int dis[N][N];
bool CASE = false;
void solve (){
    int h,w;
    cin >> h >> w;
    for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++) cin >> tab[i][j], dis[i][j] = INT_MAX;
    priority_queue<pair<int,pii>,vector<pair<int,pii>>,greater<pair<int,pii>>> pq;
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    dis[a][b] = 0;
    pii di[4] = {{0,1},{0,-1},{1,0},{-1,0}};
    pq.push({0,{a,b}});
    while(!pq.empty()){
        auto [cur,xy] = pq.top();
        auto [x,y] = xy;
        //cout << cur << " " << x << " " << y << "\n";
        pq.pop();
        if(cur > dis[x][y]) continue;
        for(int i = 0; i < 4; i++){
            auto [dx,dy] = di[i];
            int xx = x+dx, yy = y+dy;
            if(xx <= 0 || yy <= 0 || xx > h || yy > w) continue;
            if(tab[xx][yy] == '.' && dis[xx][yy] > cur){
                dis[xx][yy] = cur;
                pq.push({cur,{xx,yy}});
            }
            if(tab[xx][yy] == '#' && dis[xx][yy] > cur+1){
                dis[xx][yy] = cur+1;
                pq.push({cur+1,{xx,yy}});
            }
            xx += dx, yy += dy;
            if(xx <= 0 || yy <= 0 || xx > h || yy > w) continue;
             if(tab[xx][yy] == '#' && dis[xx][yy] > cur+1){
                dis[xx][yy] = cur+1;
                pq.push({cur+1,{xx,yy}});
            }
        }
    }
    cout << dis[c][d];

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}