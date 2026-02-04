#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
   ll n,x;
   cin >> n >> x;
   if(n == x){
     cout << x << "\n";
     return;
   }
   if(x == 0){
     int a = 0;
     for(int i = 0; i < 63; i++){
       if((1LL<<i)&n) {
           a = i;
       }
     }
     ll ans = pow(2,a+1);
     cout << ans << "\n";
     return;
   }
   ll idx = -1, c = 0;
   for(int i = 0; i < 63; i++){
       if((1LL<<i)&x) {
           idx = i;
           break;
       }
   }
   for(int i = idx-1; i > 0; i--){
       if((1LL<<i)&n){
           c = i;
           break;
       }
   }
   for(int i = idx; i < 63; i++){
      if(((1LL<<i)&n) != ((1LL<<i)&x)){
         cout << -1 << "\n";
         return;
      }
   }
   ll ans = n+((1LL<<c)-n%(1LL<<c));
   if((n&ans) == x) cout << ans << "\n";
   else cout << -1 << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--)
    {   
        solve();
    }

}