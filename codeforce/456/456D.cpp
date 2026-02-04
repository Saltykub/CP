#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 1e5+10;
const int mod = 1e9+7;
bool CASE = false;
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
int dfs(int node, int lv){
    int ret = 0;
    vector<int> ch(4,0);
    int df;
    for(int k = 0; k < 26; k++){
        if(trie[node][k] == 0) continue;
         df = dfs(trie[node][k],lv+1);
         ch[df] = 1;
    }
    return ret+1;
}
void solve (){
    ll n,k;
    cin >> n >> k; 
    vector<string> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        add(v[i]);
    }
    int e = 0, o = 0;
    for(int i = 0; i < 26; i++){
        if(trie[0][i]) {
            int ret = dfs(trie[0][i],1);
            if(ret % 2) o = 1;
            else e = 1;
        }
    }

    if(e&o) cout << "First";
    else {
        if(e) cout << "Second";
        else {
            if(k%2) cout << "First";
            else cout << "Second";
        }
    }
    cout << "\n";

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
