#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
#define piii = pair<ll,pii> 
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    ll n,x;
    cin >> n >> x;
    vector<pair<ll,pii>> v(n); 
    ll cur = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i].st >> v[i].nd.st >> v[i].nd.nd;
    }
    sort(all(v),[&](pair<ll,pii> a,pair<ll,pii> b) {
        if(a.st*a.nd.st-a.nd.nd == b.st*b.nd.st-b.nd.nd){
            return a.st*(a.nd.st-1) > b.st*(b.nd.st-1);
        }
        return a.st*a.nd.st-a.nd.nd > b.st*b.nd.st-b.nd.nd;
    });
    for(int i = 0; i < n; i++) x -= (v[i].nd.st-1)*v[i].st;
    if(x <= 0){
        cout << 0 << "\n";
    }
    else {
        ll mx = v[0].st*v[0].nd.st-v[0].nd.nd;
        if(mx <= 0){
            cout << -1 << "\n";
            return;
        }
        ll ans = (x+mx-1)/mx;
        cout << ans;
        cout << "\n";
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