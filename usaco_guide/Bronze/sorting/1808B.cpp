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
   ll n,m,ans = 0;
   cin >> n >> m;
   vector<vector<int>> arr(m);
   for(int i = 0; i < n; i++)for(int j = 0; j < m; j++) {
        int x;
        cin >> x;
        arr[j].pb(x);
   }
   for(int i = 0; i < m; i++) sort(arr[i].begin(),arr[i].end());
   for(int i = 0; i < m; i++){
     ll sm = 0, sz = n-1;
     for(auto u:arr[i]) sm+=u;
     for(auto u:arr[i]){
        sm-=u;
        ans+=sm-u*sz;
        sz--;
     }
   }
   cout << ans << "\n";
    
}
int main(){   
   // ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--)
    {   
        solve();
    }
 
}
