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
  ll n,m,q;
  cin >> n >> m >> q;
  vector<ll> a(n), b(m);
  for(auto &x:a) cin >> x;
  for(auto &x:b) cin >> x;
  ll sma = 0, smb = 0;
  for(auto u:a) sma += u;
  for(auto u:b) smb += u;
  set<ll> sa, sb;
  for(auto u:a) sa.insert(sma-u);
  for(auto u:b) sb.insert(smb-u);
  while(q--){
    ll x;
    cin >> x;
    bool can = false;
    for(ll i = 1; i <= sqrt(abs(x)); i++){
        if(x%i == 0){
            if(sa.find(i) != sa.end()){
                if(sb.find(x/i) != sb.end()){
                    can = true;
                }
            }
            if(sb.find(i) != sb.end()){
                if(sa.find(x/i) != sa.end()){
                    can = true;
                }
            }
            ll ii = -i;
            if(sa.find(ii) != sa.end()){
                if(sb.find(x/ii) != sb.end()){
                    can = true;
                }
           }
            if(sb.find(ii) != sb.end()){
                if(sa.find(x/ii) != sa.end()){
                    can = true;
                }
           }
        }
    }
    if(can) cout << "Yes\n";
    else cout << "No\n";
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