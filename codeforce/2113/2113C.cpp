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
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<char>> tab(n+1,vector<char>(m+1));
    vector<vector<ll>> sm(n+1,vector<ll>(m+1,0));
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) {
            cin >> tab[i][j];
            if(tab[i][j] == 'g') ans++;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            sm[i][j] = sm[i-1][j] + sm[i][j-1] - sm[i-1][j-1] + (tab[i][j] == 'g');
        }
    }
    ll mn = INT_MAX;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(tab[i][j] == '.'){
                int x1 = min(i+k-1,n), y1 = min(j+k-1,m), x2 = max(i-k+1,1), y2 = max(j-k+1,1);
                mn = min(sm[x1][y1] - sm[x1][y2-1] - sm[x2-1][y1] + sm[x2-1][y2-1],mn);
            }
        }
    }
    cout << ans - mn << "\n";
    
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}