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
    ll n,m,k;
    cin >> n >> m >> k;
    vll a(n);
    set<ll> b;
    ll ans = n;
    for(auto &u:a) cin >> u;
    while(m--){
        int x;
        cin >> x;
        b.insert(x);
    }
    map<int,set<int>> mp;
    for(int i = 0; i < n; i++){
        int u = a[i];
        auto it = b.upper_bound(u);
        if(it != b.end()){
            mp[*it-u].insert(i);
        }
        it = b.lower_bound(u);
        if(it != b.begin()){
            it--;
            mp[*it-u].insert(i);
        }
    }
    string s;
    cin >> s;
    ll cur = 0;
    vll die(n,1);
    for(auto u:s){
        if(u == 'L') cur--;
        else cur++;
        for(auto idx:mp[cur]){
            if(die[idx]) {
                ans--;
                die[idx] = 0;
            }
        }
        mp[cur].clear();
        cout << ans << " ";
    }
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