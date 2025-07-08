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
    vector<vector<char>> tab(n+1,vector<char>(m+1));
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> tab[i][j];
    vector<vector<int>> qs(n+1,vector<int>(m+1,0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            qs[i][j] = tab[i][j] == '.' ? 1 : -1;
            qs[i][j] += qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1];
        }
    }
    map<pii,ll> mp;
    for(int i = 1; i <= m; i++){
        mp[{0,i}] = 1;
        mp[{0,i}] += mp[{0,i-1}];
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        map<pii,ll> st;
        for(int j = 1; j <= n; j++){
            if(qs[i][j] == 0) ans++;
            ans += mp[{qs[i][j],j}];

        }

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