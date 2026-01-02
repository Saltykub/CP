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
    vll v(n+1);
    vll idx(n+1), vis(n+1,0);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        idx[v[i]] = i;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ll cnt = 1;
        if(vis[i]) continue;
        int cur = idx[i];
        vis[i] = true;
        while(cur != i){
            vis[cur] = true;
            cur = idx[cur];
            cnt++;
        }
        ans += (cnt-1)*cnt/2;
    }
    cout << ans;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}