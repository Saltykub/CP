#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
void solve (){
   ll sm = 0, ans = 0;
   int n;
   cin >> n;
   int a[n], b[n];
   for(int i = 0; i < n; i++){
       cin >> a[i] >> b[i];
       sm += a[i];
   }
   for(int i = 0; i < n; i++){
      ans = max(ans,sm-a[i] + b[i]);
   }
   cout << ans;
   
}
int main(){   
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    // cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
}