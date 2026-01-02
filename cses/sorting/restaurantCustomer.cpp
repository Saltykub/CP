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
    vector<pii> v;
    for(int i = 0; i < n; i++){
        int l,r;
        cin >> l >> r;
        v.pb({l,1});
        v.pb({r,-1});
    }
    sort(all(v));
    ll mx = 0, sm = 0;
    for(auto [a,b]:v){
        sm+=b;
        mx = max(mx,sm);
    }
    cout << mx;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}