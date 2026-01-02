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
    vll v(n), d(n);
    for(auto &u:v) cin >> u;
    v.pb(INT_MAX);
    for(int i = 0; i < n; i++) d[i]  = v[i+1]-v[i];
    int ans = n-1;
    ll l = 0, r = 2e9;
    for(int i = 0; i < n-1; i++){
        ll nl,nr;
        nl = max(0LL,d[i]-r);
        nr = min(d[i+1],d[i]-l);
        //cout << nl << " " << nr << "\n";
        if(nl >= nr){
           // cout << "PASS";
            l = 0;
            r = min({d[i],d[i+1]});
            ans--;
        }
        else {
            l = nl;
            r = nr;
        }
        
    }
    cout << ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}