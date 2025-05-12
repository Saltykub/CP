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
   ll b,c,d;
   cin >> b >> c >> d;
   ll target = d-(b-c), ans = 0;
   if(target < 0) {
      cout << -1 << "\n";
      return;
   }
   //cout << target << "\n";
   //cout << ((1LL<<0)&b);
   for(int i = 61; i >= 0; i--){
        if((1LL<<i)&b && !((1LL<<i)&c)) continue;
        if(!((1LL<<i)&b) && ((1LL<<i)&c)){
            target-=(1ll<<i);
            continue;
        }
        if(pow(2,i) > target){
            if((1LL<<i)&b && ((1LL<<i)&c)) ans+=(1ll<<i);
            continue;
        } 
        target -= (1ll<<i);
        //cout << i << "\n";
        if(!((1LL<<i)&b) && !((1LL<<i)&c)) ans+=(1ll<<i);
   }
   if(target) cout << -1 <<"\n";
   else cout << ans << "\n";
   //cout << (ans|b) - (ans&c) <<"\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }

}