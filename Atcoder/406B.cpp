#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
ll bpow(int a,int b){
    if(b == 0) return 1;
    if(b%2) return bpow(a,b/2) * bpow(a,b/2) * a;
    return bpow(a,b/2) * bpow(a,b/2);
}
void solve (){
    int n,k;
    cin >> n >> k;
    ll mx = bpow(10,k);
    ll sm = 1;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        ll div = mx/x;
        if(mx%x == 0) div--;
        // cout << div << " ";
        if(sm <= div) sm = sm*=x;
        else sm = 1;
    }
    cout << sm;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}