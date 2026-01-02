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
bool CASE = true;
void fr(){
    int n,m;
    cin >> n >> m;
    vector<char> v(n+1,'o');
    vector<int> adj[n+1];
    while(m--){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    queue<int> q;
    q.push(1);
    v[1] = 'r';
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto u:adj[node]){
            if(v[u] != 'o') continue;
            if(v[node] == 'r') {
                v[u] = 'g';
                q.push(u);
            }
            else if(v[node] == 'g'){
                v[u] = 'b';
                q.push(u);
            }
            else {
                v[u] = 'r';
                q.push(u);
            }
        }
    }
    for(auto u:v) if(u != 'o') cout << u;
    cout << "\n";
}
void sec(){
    int q;
    cin >> q;
    while(q--){
        int n;
        string s;
        cin >> n >> s;
        bool cr = false, cb = false, cg = false;
        for(auto u:s) {
            if(u == 'r') cr = true;
            if(u == 'g') cg = true;
            if(u == 'b') cb = true;
        }
        if(!cr){
            for(int i = 0; i < n; i++) {
                if(s[i] == 'b'){
                    cout << i+1 << "\n";
                    break;
                }
            }
        }
        if(!cb){
            for(int i = 0; i < n; i++) {
                if(s[i] == 'g'){
                    cout << i+1 << "\n";
                    break;
                }
            }
        }
        if(!cg){
            for(int i = 0; i < n; i++) {
                if(s[i] == 'r'){
                    cout << i+1 << "\n";
                    break;
                }
            }
        }
    }
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    string s;
    cin >> s;
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        if(s == "first") fr();
        else sec();
    }
}