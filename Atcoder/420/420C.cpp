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
  int n,q;
  cin >> n >> q;
  vector<int> a(n), b(n);
  for(auto &u:a) cin >> u;
  for(auto &u:b) cin >> u;
  ll ans = 0;
  for(int i = 0; i < n; i++){
    ans += min(a[i],b[i]);
  }
  while(q--){
    char c;
    int idx, val;
    cin >> c >> idx >> val;
    idx--;
    if(c == 'A'){
        ans -= min(a[idx],b[idx]);
        a[idx] = val;
        ans += min(a[idx],b[idx]);
    }
    else {
        ans -= min(a[idx],b[idx]);
        b[idx] = val;
        ans += min(a[idx],b[idx]);
    }
    cout << ans << "\n";
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