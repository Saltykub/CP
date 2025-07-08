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
   int n,m,q;
   cin >> n >> m >> q;
   unordered_map<int,int> mp;
   vector<int> ord(n),si(m);
   vector<int> cnt;
   for(int i = 0; i < n; i++) {
      cin >> ord[i];
   }
   for(int i = 0; i < m; i++) {
     cin >> si[i];
     if(mp[si[i]]) continue;
     mp[si[i]] = 1;
     cnt.pb(si[i]);
   }
   for(int i = 0; i < cnt.size(); i++){
      if(ord[i]!=cnt[i]){
        cout << "TIDAK\n";
        return;
      }
   }
   cout << "YA\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }

}