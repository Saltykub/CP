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
   ll k;
   cin >> k;
   ll l = 1, r = 1e10;
   while(l<r){
      ll mid = (l+r)/2;
      if(mid*mid-mid >= k) r = mid;
      else l = mid +1;
   }
   ll ans = l+k-1;
   cout << ans  << "\n";
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