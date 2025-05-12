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
   int n,k;
   cin >> n >> k;
   vector<int> mex(n,0);
   for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if(x < n) mex[x]++;
   }
   int ans = 0;
   for(int i = 0; i < n; i++){
      if(mex[i] > 0) ans = i+1;
      else break;
      if(mex[i] > 1){
        if(i + k >= n) continue;
        mex[i+k] += mex[i]-1;
      }
   }
   cout << ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }

}