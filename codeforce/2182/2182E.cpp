#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
#define piii pair<ll,pii>
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    ll n,m,k;
    cin >> n >> m >> k;
    vll a(m);
    multiset<ll> s;
    for(auto &u:a) {
        cin >> u;
        s.insert(u);
    }
    vector<piii> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].st >> v[i].nd.st >> v[i].nd.nd;
    }
    sort(all(v),[&](piii a, piii b){
        if(a.nd.nd-a.nd.st == b.nd.nd-b.nd.st){
            return a.st < b.st;
        }
        return a.nd.nd-a.nd.st > b.nd.nd-b.nd.st;
    });
    vll cal;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        auto it = s.lower_bound(v[i].st);
        if(it != s.end()){
            s.erase(it);
            ans++;
        }
        else {
            cal.pb(v[i].nd.nd-v[i].nd.st);
        }
        k-=v[i].nd.st;
    }
    sort(all(cal));
    for(int i = 0; i < sz(cal); i++){
        if(cal[i] <= k){
            k-=cal[i];
        }
        else {
            cout << i+ans << "\n";
            return;
        }
    }
    cout << n << "\n";
    return;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}   