#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+3;
int p[N];
int fp(int node){return p[node] == node ? node : p[node] = fp(p[node]);}
void solve (){
     int n,m;
     ll ans = 0;
     cin >> n >> m;
     vector<pair<ll,vector<int>>> v;
     for(int i = 0; i < m; i++){
        int k,c;
        cin >> k >> c;
        vector<int> u;
        for(int i = 0; i < k; i++){int x; cin >> x; u.emplace_back(x);}
        v.pb({c,u});
     }
     sort(v.begin(),v.end());
     for(int i = 0; i <= n; i++) p[i] = i;
     for(int i = 0; i < m; i++){
        for(int j = 0; j < v[i].second.size(); j++){
            int u1 = v[i].second[j], u2 = v[i].second[0];
            int pu1 = fp(u1), pu2 = fp(u2);
            if(pu1 != pu2){
                //printf("u1: %d pu1: %d u2: %d pu2: %d\n", u1,pu1,u2,pu2);
                p[pu1] = pu2;
                ans+=v[i].first;
            }
        }
   
     }
     bool check = true;
     for(int i = 1; i <= n; i++) if(fp(i) != fp(1)) check = false;
     if(check) cout << ans;
     else cout << -1;
}
int main(){   
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    // cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
}