#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
void solve (){
   int n,q;
   cin >> n >> q;
   vector<string> ed (n+1);
   for(int i = 1; i <= n; i++) cin >> ed[i];
   map<string,set<int>> mp;
   for(int i = 1; i <= n; i++){
      mp[ed[i]].insert(i);
   }
   while(q--){
    int u,v;
    cin >> u >> v;
    if(u > v) swap(u,v);
    bool check = false;
    for(auto x:ed[u]){
        if(x == ed[v][0] || x == ed[v][1]) check = true;
    }
    if(check) cout << abs(u-v) << "\n";
    else {
        int ans = INT_MAX;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                string mid = "";
                mid += ed[u][i];
                mid += ed[v][j];
                sort(mid.begin(),mid.end());
                if(mp[mid].size()){
                    auto ch =upper_bound(mp[mid].begin(),mp[mid].end(),u);
                    if(ch != mp[mid].end()) ans = min(ans,abs(u-*ch)+abs(v-*ch));
                    ch = lower_bound(mp[mid].begin(),mp[mid].end(),u);
                    if(ch != mp[mid].begin()) {
                        ch--;
                        ans = min(ans,abs(u-*ch)+abs(v-*ch));
                    }
                    ch = lower_bound(mp[mid].begin(),mp[mid].end(),v);
                    if(ch != mp[mid].begin()) {
                        ch--;
                        ans = min(ans,abs(u-*ch)+abs(v-*ch));
                    }
                    ch =  upper_bound(mp[mid].begin(),mp[mid].end(),v);
                    if(ch != mp[mid].end()) ans = min(ans,abs(u-*ch)+abs(v-*ch));
                }
            }
        }
        if(ans == INT_MAX) cout << -1 << "\n";
        else cout << ans << "\n";
        //cout << "pass";
    }
   }
   
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    // t=1;
    while(t--)
    {   
        solve();
    }

}