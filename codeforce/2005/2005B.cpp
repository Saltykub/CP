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
   ll n,m,q;
   cin >> n >> m >> q;
   vector<int> t(m,0);
   for(int i = 0; i < m; i++) cin >> t[i];
   sort(t.begin(),t.end());
   while(q--){
      int x;
      cin >> x;
      int l,r;
      auto lb = lower_bound(t.begin(),t.end(),x);
      if(t[0] > x) l = 0;
      else l = *(--lb);
      auto ub = upper_bound(t.begin(),t.end(),x);
      if(x > t[m-1]) r = n+1;
      else r = *ub;
      if(l == 0){
         cout << r-1 ;
      }
      else if ( r == n+1){
         cout << n-l;
      }
      else {
        cout << int(ceil(1.0*(r-l-1)/2));
      }
      cout << "\n";
      //cout << l << " " << r << "\n";
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