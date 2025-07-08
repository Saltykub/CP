#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    int n;
    cin >> n;
    vector<vector<int>> tab(n,vector<int>(n,-1));
    int val=(n*n)-1;
    int x = 0, y = 0;
    pii di[4] = {{0,1},{1,0},{0,-1},{-1,-0}};
    int nxt = 0;
    while(val >= 0){
        //cout << x << " " << y << "\n";
        tab[x][y] = val;
        val--;
        if(val < 0) break;
        int nx = x+di[nxt].st, ny = y+di[nxt].nd;
        if(nx >= n || ny >= n || nx < 0 || ny < 0 || tab[nx][ny] != -1) {
            nxt+= 1;
            nxt%=4;
        }
        x += di[nxt].st;
        y += di[nxt].nd;
    }
    for(auto u:tab){
        for(auto v:u) cout << v << " ";
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