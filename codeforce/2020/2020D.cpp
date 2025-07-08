#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
vector<int> p(N);
int fp(int a) {return (p[a] == a) ? a : p[a] = fp(p[a]);}
void com(int a,int b){
    int pa = fp(a), pbb = fp(b);
    if(pa != pbb) p[pbb] = pa;
}
void solve (){
   int n,m;
   cin >> n >> m;
   for(int i = 1; i <= n; i++) p[i] = i;
   vector<pii> v[11][11];
   for(int i = 0; i < m; i++) {
      int a,d,k;
      cin >> a >> d >> k;
      v[d][a%d].pb({a,k});
   }
   for(int i = 1; i <= 10; i++){
       for(int j = 0; j < i; j++){
           ll mx = 0;
           if(v[i][j].empty()) continue;
           sort(v[i][j].begin(),v[i][j].end());
           for(auto [a,k]:v[i][j]){
               int cur = a;
               if(a < mx) {
                 com(a,mx);
                 cur = mx;
               }
               while(cur <= a+k*i){
                    com(cur,a);
                    cur+=i;
               }
               mx = max(mx,a+k*i);
           }
       }
   }
   int ans = n;
   for(int i = 1; i <= n; i++) if(fp(i) != i) ans--;
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