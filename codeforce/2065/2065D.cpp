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
    vector<vector<ll>> v(n,vector<ll>(m));
    for(int i = 0; i < n; i++)for(int j = 0; j < m; j++) cin >> v[i][j];
    vector<pair<ll,vector<ll>>> cal;
    for(int i = 0; i < n; i++){
        ll sm = 0;
        for(int j = 0; j < m; j++){
            sm += v[i][j];
        }
        //cout << sm << "\n";
        cal.pb({sm,v[i]});
    }
    sort(cal.begin(),cal.end(),[&](pair<ll,vector<ll>> a, pair<ll,vector<ll>> b){
        return a.st > b.st;
    });
    vector<ll> ans;
    for(auto u:cal){
        //cout << u.st << "\n";
        for(auto v:u.nd){
            ans.pb(v);
        }
    }
    for(int i = 1; i < ans.size(); i++) ans[i] += ans[i-1];
    ll sm = 0;
    for(auto u:ans) sm += u;
    cout << sm << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}