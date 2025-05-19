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

ll choose(int n, int r){
    ll ret = 1, sm = 1;
    for(int i = 0; i < r; i++){
        ret *= (n-i);
        sm *= (i+1);
    }
    return ret/sm;
}
void solve (){
    ll n,k;
    cin >> n >> k;
    ll cnt = 1;
    if(k >= 2) cnt += choose(n,2);
    if(k >= 3) cnt += choose(n,3) * 2;
    if(k >= 4) cnt += choose(n,4) * 9;
    cout << cnt;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}