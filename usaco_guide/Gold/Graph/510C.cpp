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
    int n;
    cin >> n;
    vector<string> s(n);
    for(auto &x:s) cin >> x;
    set<int> adj[26];
    vector<int> in(26,0);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int idx = 0;
            while(true){
                if(s[i][idx] != s[j][idx]){
                    break;
                }
                else {
                    idx++;
                    if(idx == s[i].size()) break;
                    if(idx == s[j].size()){
                        cout << "Impossible";
                        return;
                    }
                }
            }
            if(idx == s[i].size()) continue;
            adj[s[i][idx]-'a'].insert(s[j][idx]-'a');
        }
    }
    //cout << "pass";
    vector<int> edge[26];
    for(int i = 0; i < 26; i++){
        for(auto u:adj[i]){
            edge[i].pb(u);
            in[u]++;
        }
    }
    string ans = "";
    queue<int> q;
    for(int i = 0; i < 26; i++){
        if(in[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int fr = q.front();
        ans += char('a'+fr);
        q.pop();
        for(auto u:edge[fr]){
            in[u]--;
            if(in[u] == 0) q.push(u);
        }
    }
    for(int i = 0; i < 26; i++){
        if(in[i] != 0) {
            cout << "Impossible";
            return;
        }
    }
    string t = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i < 26; i++){
        bool have = false;
        for(int j = 0; j < ans.size(); j++){
            if(ans[j] == t[i]) have = true;
        }
        if(!have) ans += t[i];
    }
    cout << ans;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}