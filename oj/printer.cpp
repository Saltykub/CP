#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<int,int>
#define nd second
#define pb push_back
using namespace std;
const int N = 5e5+10;
bool CASE = false;
int mxword[N];
int trie[N][26]; // trie[i][c] mean node number that contain character c and is a child of node i
int nxt;
bool stop[N]; 
void add(string s){
    int cur = 0;
    for(auto u:s){
        if(trie[cur][u-'a'] == 0) trie[cur][u-'a'] = ++nxt; // build new node
        cur = trie[cur][u-'a']; // go to next node 
    }
    stop[cur] = true; // show that current node is end node
}
vector<char> ans;
void dfs(int node){
    if(stop[node]) ans.push_back('P');
    vector<pii> start;
    for(int i = 0; i < 26; i++) if(trie[node][i]) start.push_back({mxword[trie[node][i]],i});
    sort(start.begin(),start.end());
    for(auto k:start){
        if(trie[node][k.second] == 0) continue;
        ans.push_back(k.second+'a');
        dfs(trie[node][k.second]);
    }
    ans.push_back('-');
    return;
}
void dfs3(int node,int lv){
    mxword[node] = lv;
    for(int k = 0; k < 26; k++){
        if(trie[node][k] == 0) continue;
        dfs3(trie[node][k],lv+1);
        mxword[node] = max(mxword[node],mxword[trie[node][k]]);
    }
    return;
}
void solve (){
    ll n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        add(v[i]);
    }
    vector<pii> start;
    for(int i = 0; i < 26; i++) if(trie[0][i]) {dfs3(trie[0][i], 1); start.push_back({mxword[trie[0][i]],i});}
    sort(start.begin(),start.end());
    for(auto i:start){
        if(trie[0][i.second]) {
            ans.push_back(i.second+'a');
            dfs(trie[0][i.second]);
        }
    }
    while(ans.back() == '-') ans.pop_back();
    cout << ans.size() << "\n";
    for(auto u:ans){
        cout << u << "\n";
    }

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--)
    {   
        solve();
    }
 
}
