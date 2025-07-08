#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
    int n,m;
    cin >> n >> m;
    vector<int> v[m];
    for(int i = 0; i < m; i++){
        int k;
        cin >> k;
        while(k--) {
            int x;
            cin >> x;
            v[i].pb(x);
        }
    }
    vector<int> order(n+1,0);
    vector<int> q(n);
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        order[x] = i;
        q[i-1] = x;
    }
    vector<int> cnt(n+1,0);
    for(int i = 0; i < m; i++){
        int mx = 0;
        int idx = 0;
        for(auto u:v[i]){
            //cout << u << " ";
            if(order[u] > mx){
                mx = order[u];
                idx = u;
            }
        }
       // cout << "\n";
        cnt[idx]++;
    }
    int ans = 0;
    for(auto u:q) {
        ans += cnt[u];
        cout << ans << "\n";
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