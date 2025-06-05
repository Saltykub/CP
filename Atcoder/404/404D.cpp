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
    vector<int> c(2*n,0);
    vector<int> zoo[2*n];
    for(int i = 0; i < n; i++) {
        cin >> c[2*i];
        c[2*i+1] = c[2*i];
    }
    for(int i = 0; i < m; i++){
        int z;
        cin >> z;
        while(z--){
            int x;
            cin >> x;
            x--;
            zoo[2*x].pb(i);
            zoo[2*x+1].pb(i);
        }
    }
    ll ans = LONG_LONG_MAX;
    n*=2;
    for(int i = 0; i < (1<<n); i++){
        vector<int> mp(m);
        ll cur = 0;
        for(int j = 0; j < n; j++){
            if((1<<j)&i){
                cur+=c[j];
                for(auto ani:zoo[j]) {
                    mp[ani]++;
                }
            }
        }
        int ch = 0;
        for(auto u:mp){
            if(u >= 2) ch++;
        }
        if(ch == m) ans = min(ans,cur);
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