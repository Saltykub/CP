#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve (){
   int n;
   cin >> n;
   vector<int> a(n,0),cnt(n+1,0),b(n,0),c(n,0);
   for(int i = 0; i < n; i++) cin >> a[i];
   ll mx = 0, ans = 0, sm = 0;
   for(int i = 0; i < n; i++){
      cnt[a[i]]++;
      if(a[i] >= mx){
        if(cnt[a[i]] >= 2) mx = a[i];
      }
      b[i] = mx;
      ans += a[i];
   }
   mx = 0;
   for(int i = 1; i <= n; i++) cnt[i] = 0;
   for(int i = 0; i < n; i++){
      cnt[b[i]]++;
    //   cout << b[i];
      ans += b[i];
      if(b[i] >= mx){
        if(cnt[b[i]] >= 2) mx = b[i];
      }
      c[i] = mx;
      sm += c[i];
   }
   int start = -1;
   for(int i = 0; i < n; i++){
    if(c[i]!=0) {
        start = i;
        break;
     }
   }
   if(start != -1){
   for(int i = start; i < n; i++){
     ans += sm;
     sm -= c[n-i + start -1];
   }
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