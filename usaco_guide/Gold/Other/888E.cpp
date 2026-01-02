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
    ll n,m;
    cin >> n >> m;
    vll v(n);
    for(auto &u:v) cin >> u;
    set<ll> s;
    ll mn = min(18LL,n);
    for(ll i = 0; i < (1LL<<mn); i++){
        ll cal = 0;
        for(int j = 0; j < n; j++){
            if((1LL<<j)&i){
                cal += v[j];
                cal %= m;
            }
        }
        cal += m;
        cal %= m;
        s.insert(cal);
    }
    if(n <= 18){
        auto it = s.end();
        it--;
        cout << *it;
    }
    else {
        vll left;
        ll mx = 0;
        for(int i = 18; i < n; i++) left.pb(v[i]);
        for(ll i = 0; i < (1LL<<sz(left)); i++){
            ll cal = 0;
            for(int j = 0; j < sz(left); j++){
                if((1LL<<j)&i){
                    cal += left[j];
                    cal %= m;
                }
            }
            cal += m;
            cal %= m;
            ll target = m-1-cal;
            auto it = s.upper_bound(target);
            if(it == s.begin()){
                it = s.end();
            }
            it--;
            cal += *it;
            cal += m;
            cal %= m;
            mx = max(mx,cal);
        }
        cout << mx;
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