#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 1e6+10;
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
void solve (){
    string s;
    cin >> s;
    int n;
    cin >> n; 
    vector<string> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        add(v[i]);
    }
    vector<int> dp(s.size() + 1); // dp[i] = number of solution that can construct s[i...s.size()]
    dp[s.size()] = 1;
    for(int i = s.size()-1; i >= 0; i--){
        int node = 0;
        for(int j = i; j < s.size(); j++){
            if(!trie[node][s[j]-'a']) break;
            node = trie[node][s[j]-'a']; 
            if(stop[node]) dp[i] = (dp[i] + dp[j+1]) %mod;
        }
    }
    cout << dp[0];
 //   cout << dp[1];
    
}
int main(){   
   // ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--)
    {   
        solve();
    }
 
}
