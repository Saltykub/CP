#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    int n,c;
    cin >> n >> c;
    char tab[n+1][n+1];
    bool vis[n+1][n+1];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) {
            cin >> tab[i][j];
            vis[i][j] = false;
        }
    }
    vll cut(n+1,-1);
    for(int j = 1; j <= n; j++){
        for(int i = n; i >= 1; i--){
            if(tab[i][j] == '#'){
                cut[j] = i;
                break;
            }
        }
    }
    queue<pii> q;
    q.push({n,c});
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        if(vis[x][y]) continue;
        vis[x][y] = true;
        //cout << x << " " << y << "\n";
        if(x-1 == 0) continue;
        if(y-1 > 0){
            if(!vis[x-1][y-1]){
                if(cut[y-1] <= x-1){
                    for(int i = x-1; i >= 1; i--){
                        if(!vis[i][y-1]) q.push({i,y-1});
                    }
                    cut[y-1] = INT_MAX;
                }
                else {
                    if(tab[x-1][y-1] != '#'){
                        q.push({x-1,y-1});
                    }
                }
            }
        }
        if(y+1 <= n){
            if(!vis[x-1][y+1]){
                if(cut[y+1] <= x-1){
                    for(int i = x-1; i >= 1; i--){
                        if(!vis[i][y+1]) q.push({i,y+1});
                    }
                    cut[y+1] = INT_MAX;
                }
                else {
                    if(tab[x-1][y+1] != '#'){
                        q.push({x-1,y+1});
                    }
                }
            }
        }
        if(!vis[x-1][y]){
            if(cut[y] <= x){
                for(int i = x-1; i >= 1; i--){
                    if(!vis[i][y+1]) q.push({i,y});
                }
                cut[y] = INT_MAX;
            }
            else {
                if(tab[x-1][y] != '#'){
                    q.push({x-1,y});
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(vis[1][i]) cout << 1;
        else cout << 0;
    }
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}