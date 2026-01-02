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
    ll n,k;
    cin >> n >> k;
    vll v(n);
    for(auto &u:v) cin >> u;
    set<ll> s,ch;
    vll ret;
    for(auto u:v) s.insert(u);
    ch = s;
    sort(all(v));
    for(int i = 0; i < n; i++){
        if(!ch.count(v[i])) continue;
        for(int j = v[i]; j <= k; j += v[i]){
            if(s.count(j)){
                // cout << j << " ";
                if(ch.count(j)) ch.erase(j);
            }
            else {
                cout << -1 << "\n";
                return;
            }
        }
        ret.pb(v[i]);
    }
    cout << ret.size() << "\n";
    for(auto u:ret) cout << u << " ";
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}