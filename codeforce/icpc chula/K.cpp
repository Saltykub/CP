#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int mod = 1e9+7;
void solve(){
   ll n,m,k;
   cin >> n >> m >> k;
   vector<pair<ll,ll>> p(n);
   vector<ll> q((1<<15)+5,INT_MAX);
   for(int i = 0; i < n; i++){
        ll nn,c,po = 0;
        cin >> nn >> c;
        p[i].st = c;
        while(nn--){
            int t; cin >> t;
            t--;
            po|=(1<<t);
        }
        p[i].nd = po;
   }
   sort(p.begin(),p.end());
   for(int i = 0; i < n; i++){
        vector<int> curr;
            for(int j = 0; j < k; j++){
                if((p[i].nd & (1<<j))){
                    if(curr.empty()) {
                        q[(1<<j)] = min(p[i].st,q[(1<<j)]);
                        curr.push_back((1<<j));
                    }
                    else {
                        vector<int> temp;
                        for(auto u:curr){
                            int idx = u;
                            idx = u|(1<<j);
                            temp.push_back(idx);
                            q[idx] = min(q[idx],p[i].st);
                           // cout << idx << " ";
                        }
                        q[(1<<j)] = min(p[i].st,q[(1<<j)]);
                        curr.push_back((1<<j));
                        for(auto u:temp) curr.push_back(u);
                    }
                }
            }
        q[p[i].nd] = min(q[p[i].nd],p[i].st);
   }
   for(int i = 0; i < n; i++){
      for(int j = 0; j < (1<<k); j++){
         if(j&p[i].nd){
            q[j] = min(q[j],q[j&(~p[i].nd)]+p[i].st);
         }
      }
   }
   while(m--){
     int M;
     cin >> M;
     ll ans = 0;
     while(M--){
        int x; cin >> x;
        x--;
        ans|=(1<<x);
     }
     if(q[ans] == INT_MAX) cout << -1;
     else cout << q[ans];
     cout << "\n";
   }
   // fix issue
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    // cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
}