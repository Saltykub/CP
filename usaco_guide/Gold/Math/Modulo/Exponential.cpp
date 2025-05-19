#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
const ll mod = 1e9+7;
bool CASE = true;
ll bpow(ll a, ll b){
    if(b == 0) return 1;
    if(b%2){
        return ((bpow(a,b/2)*bpow(a,b/2))%mod * a)%mod;
    }
    return (bpow(a,b/2)*bpow(a,b/2))%mod;
}
void solve (){
    ll a,b;
    cin >> a >> b;
    cout << bpow(a,b) << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}