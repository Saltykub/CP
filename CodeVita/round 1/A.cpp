#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
char tab[60][60];
void solve (){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> tab[i][j];
        }
    }
    string path;
    cin >> path;
    pii di[4] = {{0,1},{1,0},{0,-1},{-1,0}};
    set<pii> s;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int d = 0; d < 4; d++){
                int nxt = d;
                int x = i, y = j;
                if(tab[x][y] == '#') continue;
                bool can = true;
                for(auto p:path){
                    if(p == 'S'){
                        x+=di[nxt].st;
                        y+=di[nxt].nd;
                    }
                    else if(p == 'L'){
                        nxt+=3;
                        nxt%=4;
                        // x+=di[nxt].st;
                        // y+=di[nxt].nd;
                    }
                    else if(p == 'R'){
                        nxt++;
                        nxt%=4;
                        // x+=di[nxt].st;
                        // y+=di[nxt].nd;
                    }
                    if(x < 0 || y < 0 || x >= n || y >= m || tab[x][y] == '#') {
                        can = false;
                        break;
                    }
                }
                if(can){
                    s.insert({x,y});
                }
            }
        }
    }
    //for(auto [x,y]:s) cout << x << " " << y << "\n";
    if(s.size() == 0) cout << "Impossible";
    else cout << s.size();
    
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}