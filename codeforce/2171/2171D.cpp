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
    int n;
    cin >> n;
    vll p(n);
    for(auto &u:p) cin >> u;
    vector<int> idx(n+1,0), vis(n+1,0);
    for(int i = 0; i < n; i++) idx[p[i]] = i;
    vector<pii> t;
    ll mx = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            vis[i] = 1;
            ll cur = 0;
            for(int j = idx[i]+1; j < n; j++){
                if(vis[p[j]]) break;
                vis[p[j]] = 1;
                t.pb({i,p[j]});
                cur = max(cur,p[j]);
            }
            if(mx != 0){
                if(mx < i){
                    cout << "No\n";
                    return;
                }
                t.pb({i,mx});
            }
            mx = max(mx,cur);
        }
    }
    if(t.size() != n-1) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    // for(auto u:t){
    //     cout << u.st << " " << u.nd << "\n";
    // }
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}