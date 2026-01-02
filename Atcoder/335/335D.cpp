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
bool CASE = false;
void solve (){
    int n;
    cin >> n;
    string tab[n+1][n+1];
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) tab[i][j]  = "T";
    int cur = 1, idx = 0, x = n, y = 1;
    pii di[4] = {{0,1},{-1,0},{0,-1},{1,0}};
    while(true){
        if(x == (n+1)/2 && y == (n+1)/2) break;
        tab[x][y] = to_string(cur);
        cur++;
        int nx = x+di[idx].st , ny = y+di[idx].nd;
        if(nx <= 0 || ny <= 0 || nx > n || ny > n || tab[nx][ny] != "T" ){
            idx++;
            idx %= 4;
            nx = x+di[idx].st;
            ny = y+di[idx].nd;
        }
        x = nx;
        y = ny;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++){
            cout << tab[i][j] << " ";
        }
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