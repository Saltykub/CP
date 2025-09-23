#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
const int MOD = 1e9+7;
bool CASE = false;
ll bpow(int a,int b){
    if(b == 0) return 1;
    if(b%2) return bpow(a,b/2) * bpow(a,b/2) % MOD * a %MOD;
    return bpow(a,b/2) * bpow(a,b/2)%MOD;
}
void solve (){
    ll n,p;
    cin >> n >> p;
    cout << (p-1)*bpow(p-2,n-1)%MOD;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}