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
  ll ans = 0;
  vector<ll> a(n),b(n);
  ll mx = 0;
  for(int i = 0; i < n; i++) {
   // mx = max((n-i)*(i+1)*100,mx);
   cin >> a[i];
    a[i]*=(n-i)*(i+1);
  }
  for(int i = 0; i < n; i++) cin >> b[i];
  sort(a.begin(),a.end());
  sort(b.begin(),b.end(),greater<ll>());
  for(int i = 0; i < n; i++) ans+= a[i]*b[i];
  cout << ans << "\n";
  //cout << mx;
}
int main(){   
   // ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--)
    {   
        solve();
    }
 
}
