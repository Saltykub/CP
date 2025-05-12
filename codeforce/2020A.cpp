#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
ll bpow (ll a, ll b){
    if(b == 0) return 1;
    ll ret = bpow(a,b/2);
    if(b%2) return ret * ret * a;
    return ret*ret;
}
void solve (){
    ll n,k;
    cin >> n >> k;
    ll cnt = 0;
    while(n){
        ll p = log(n)/log(k);
        if(bpow(k,p) == 0) {
            cnt += n;
            break;
        }
        ll po = bpow(k,p);
        ll cur = n/po;
        n-=cur*po;
        cnt+=cur;
    }
    cout << cnt << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }

}