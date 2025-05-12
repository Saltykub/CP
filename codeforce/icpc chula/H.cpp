#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int mod = 1e9+7;
ll mpow(ll a, ll p){
    if(p == 0) return 1;
    if(p % 2 == 0) {
        return (mpow(a,p/2)%mod) * (mpow(a,p/2)%mod) %mod;
    }
    else {
        return (a%mod) * (mpow(a,p/2)%mod)%mod * (mpow(a,p/2)%mod)%mod;
    }
}
void solve(){
   ll n,k;
   cin >> n >> k;
   if(n%3 == 0){
       n/=3;
       cout << (k%mod) * mpow(k-1,n-1) % mod;
   }
   else if (n%3 == 1){
      n/=3;
      cout << (n+1)%mod*k%mod*mpow(k-1,n)%mod;
   }
   else {
      n/=3;
      ll ans = (n+1)%mod*k%mod*mpow(k-1,n)%mod;
      ans += (n+1)%mod * k%mod * mpow(k-1,n+1)%mod;
      ans += ((n+1)*n/2%mod)*k%mod*mpow(k-1,n+1)%mod;
      cout << ans%mod;
   }
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    // cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
}