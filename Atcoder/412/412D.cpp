#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1];
    map<pii,int> mp;
    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        if(u > v) swap(u,v);
        mp[{u,v}] = 1;
    }
    vector<int> permu;
    ll ans = INT_MAX;
    for(int i = 1; i <= n; i++) permu.pb(i);
    do{
        // 1 cycle 
        ll cal = m;
        for(int i = 0; i < n-1; i++){
            int u = permu[i], v = permu[i+1];
            if(u > v) swap(u,v);
            if(mp[{u,v}]) cal--;
            else cal++;
        }
        if(mp[{min(permu[0],permu[n-1]),max(permu[0],permu[n-1])}]) cal--;
        else cal++;
        ans = min(ans,cal);
        // 2 cycle 
        for(int j = 3; j <= n-3; j++){
            cal = m;
            for(int i = 0; i < j-1; i++){
                //cout << permu[i] << " ";
                int u = permu[i], v = permu[i+1];
                if(u > v) swap(u,v);
                if(mp[{u,v}]) cal--;
                else cal++;
            }
            //cout << permu[j-1] << "\n";
            if(mp[{min(permu[0],permu[j-1]),max(permu[0],permu[j-1])}]) cal--;
            else cal++;
            for(int i = j; i < n-1; i++){
                //cout << permu[i] << " ";
                int u = permu[i], v = permu[i+1];
                if(u > v) swap(u,v);
                if(mp[{u,v}]) cal--;
                else cal++;
            }
            //cout << permu[n-1] << "\n";
            if(mp[{min(permu[j],permu[n-1]),max(permu[j],permu[n-1])}]) cal--;
            else cal++;
            ans = min(ans,cal);
        }

    }while(next_permutation(permu.begin(),permu.end()));
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