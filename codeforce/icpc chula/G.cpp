#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int mod = 1e9+7;
const int N = 2e5+10;
vector<pair<ll,ll>> arr(N);
vector<ll> ans(N,-1);
void solve(){
   ll n,m,h,q;
   cin >> n >> m >> h >> q;
   for(int i = 0; i < n; i++) cin >> arr[i].st >> arr[i].nd;
   for(int i = 0; i < n; i++) arr[i].nd = abs(arr[i].nd - h);
   multiset<ll> s;
   for(int i = 0; i < m; i++){
       ll x;
       cin >> x;
       s.insert(x);
   }
   ll cnt = 0;
   for(int i = 0; i < n; i++){
        auto it = s.lower_bound(arr[i].nd);
        if(it != s.end()){
            s.erase(it);
            cnt ++;
            ans[cnt] = arr[i].st;
        }
   }
   while(q--){
      ll x;
      cin >> x;
      cout << ans[x] << "\n";
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