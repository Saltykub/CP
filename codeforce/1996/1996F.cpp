#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int mod = 1e9+7;
void solve(){
   int n,k;
   cin >> n >> k;
   vector<int> a(n),b(n);
   for(int i = 0; i < n; i++) cin >> a[i];
   for(int i = 0; i < n; i++) cin >> b[i];
   priority_queue<pii> pq;
   for(int i = 0; i < n; i++){
       pq.push({a[i],b[i]});
   }
   ll ans = 0;
   while(k--){
     int aa = pq.top().st, bb = pq.top().nd;
     ans += aa;
     pq.pop();
     pq.push({max(aa-bb,0),bb});
   }
   cout << ans << "\n";
 
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    // t=1;
    while(t--)
    {
        solve();
    }
}