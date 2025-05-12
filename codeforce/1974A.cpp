#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb emplace_back
using namespace std;
void solve (){
   int x,y;
   cin >> x >> y;
   int ans = y/2;
   x-= (7*ans); 
   y-= (2*ans);
   if(y){
      ans++;
      x-=11;
      if(x <= 0) cout << ans;
      else cout << ans+ceil(1.0*x/15); 
   }
   else {
      x = max(x,0);
      cout << ceil(1.0*x/15) + ans;
   }
   cout << "\n";

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    // if(t!=11){
    //     for(int i = 1; i <= t; i++) {
    //         int x,y;
    //         cin >> x >> y;
    //         if(i == 1002) cout << x << " " << y;
    //     }
    //     return 0;
    // }
    // t=1;
    while(t--)
    {
        solve();
    }
}