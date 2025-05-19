#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
    ll n;
    cin >> n;
    vector<int> v(n,0);
    v[1] = 1;
    ll p = 1;
    for(ll i = 2; i < n; i++){
       if(__gcd(i,n) == 1){
            v[i] = 1;
            p*=i;
            p%=n;
       }
    }
    if(p!=1) v[p] = 0;
    ll cnt = 0;
    for(int i = 0; i < n; i++) if(v[i]) cnt++;
    cout << cnt << "\n";
    for(int i = 0; i < n; i++) if(v[i]) cout << i << " ";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}