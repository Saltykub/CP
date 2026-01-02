#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
using namespace std;
const int N = 2e5+10;
const ll MAX = 1e9;
bool CASE = false;
vector<int> adj[N];
vector<int> deg(N,0);
void solve (){
    int n,m;
    cin >> n >> m;
    int cnt = 0;
    unordered_map<ll,ll> mp;
    vector<vector<ll>> ing(m,vector<ll>(10,0));
    vector<ll> val(10);
    for(int i = 1; i <= m; i++){
        int c;
        cin >> c;
        if(c == 0){
            ll x;
            cin >> x;
            val[cnt] = x;
            mp[i] = cnt;
            cnt++;
        }
        else {
            for(int j = 0; j < c; j++){
                int x;
                cin >> x;
                adj[x].pb(i);
                deg[i]++; 
            }
        }
    }
    queue<int> q;
    for(int i = 1; i <= m; i++){
        if(deg[i] == 0){
            for(auto u:adj[i]){
                ing[u][mp[i]]++;
                deg[u]--;
                if(deg[u] == 0) q.push(u);
            }
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto u:adj[node]){
            for(int i = 0; i < 10; i++){
                ing[u][i] += ing[node][i];
                ing[u][i] = min(ing[u][i],MAX);
            }
            deg[u]--;
            if(deg[u] == 0) q.push(u);
        }
    }
    int mx = 0;
    for(int i = 0; i < (1LL<<n); i++){
        vector<ll> ch(10,0);
        bool can = true;
        for(int j = 0; j < n; j++){
            if((1LL<<j)&i){
                if(deg[j+1] != 0) {
                    can = false;
                    break;
                }
                for(int k = 0; k < 10; k++){
                    ch[k] += ing[j+1][k];
                }
            }
        }
        for(int k = 0; k < 10; k++){
            if(ch[k] > val[k]) {
                can = false;
                break;
            }
        }
        if(can){
            mx = max(mx,__builtin_popcount(i));
        }
    }
    cout << mx;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}