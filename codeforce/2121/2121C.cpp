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
    vector<vector<int>> tab(n,vector<int>(m));
    int l = 0, r = 0;
    int ans = 0;
    int mx = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> tab[i][j];
            if(tab[i][j] > mx){
                l = i, r = j;
                mx = tab[i][j];
            }
        }
    }
    vector<vector<int>> tmp = tab;
    int tl = 0, tr = 0;
    int tmx = 0;
    for(int j = 0; j < m; j++){
        tmp[l][j]--;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
           // cout << tmp[i][j] << " ";
            if(tmp[i][j] > tmx){
                tl = i;
                tr = j;
                tmx = tmp[i][j];
            }
        }
    }
    for(int i = 0; i < n; i++){
        tmp[i][tr]--;
    }
    tmp[l][tr]++;
    tmx = 0;
    for(auto u:tmp) for(auto v:u) tmx = max(tmx,v);
    ans = tmx;
    tmp = tab;
    tl = 0, tr = 0;
    tmx = 0;
    for(int j = 0; j < n; j++){
        tmp[j][r]--;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(tmp[i][j] > tmx){
                tl = i;
                tr = j;
                tmx = tmp[i][j];
            }
        }
    }
    for(int i = 0; i < m; i++){
        tmp[tl][i]--;
    }
    tmx = 0;
    tmp[tl][r]++;
    for(auto u:tmp) for(auto v:u) tmx = max(tmx,v);
    cout << min(ans,tmx) << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}