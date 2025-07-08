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
    int n,m;
    cin >> n >> m;
    int tab[n][m];
    bool vis[n][m];
    vector<string> v(n);
    for(auto &s:v) cin >>s;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            if(v[i][j] == '1') tab[i][j] = 1;
            else tab[i][j] = 0;
            vis[i][j] = false;
        }
    }
   
    for(int i = 0; i < n; i++){
        if(tab[i][0] == 1){
            for(int j = 0; j < m; j++){
                if(tab[i][j]){
                    vis[i][j] = true;
                }
                else break;
            }
        }
    }
    for(int j = 0; j < m; j++){
        if(tab[0][j]){
            for(int i = 0; i < n; i++){
                if(tab[i][j]){
                    vis[i][j] = true;
                }
                else break;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(tab[i][j] && !vis[i][j]){
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}