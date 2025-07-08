#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 5e5+10;
bool CASE = false;
ll tx[N][26], ty[N][26];
vector<ll> cntx(N), cnty(N);
ll nxtx = 1, nxty = 1;
ll ans = 0;
void addx(string s){
   int v = 0;
   for(auto ch:s){
      int c = ch-'a';
      if(tx[v][c] == -1) tx[v][c] = nxtx++;
      v = tx[v][c];
   }
   cntx[v]++;
}
void addy(string s){
   int v = 0;
   for(auto ch:s){
      int c = ch-'a';
      if(ty[v][c] == -1) ty[v][c] = nxty++;
      v = ty[v][c];
   }
   cnty[v]++;
   ans++;
}
bool chy(string s){
   int v = 0;
   for(auto ch:s){
      int c = ch-'a';
      if(cntx[v]) return false;
      if(tx[v][c] == -1) return true;
      v = tx[v][c];
   }
   if(cntx[v]) return false;
   return true;
}
void chx(string s){
    int v = 0;
    for(auto ch:s){
        int c = ch-'a';
        if(ty[v][c] == -1) return;
        v = ty[v][c];
    }
    ans -= cnty[v];
    cnty[v] = 0;
    queue<int> q;
    for(int i = 0; i < 26; i++){
        if(ty[v][i] != -1){
            q.push(ty[v][i]);
            ans -= cnty[ty[v][i]];
            cnty[ty[v][i]] = 0;
            ty[v][i] = -1;
        }
    }
    while(!q.empty()){
        int node = q.front();
        //cout << node << "\n";
        q.pop();
        for(int i = 0; i < 26; i++){
            if(ty[node][i] != -1){
                q.push(ty[node][i]);
                ans -= cnty[ty[node][i]];
                cnty[ty[node][i]] = 0;
                ty[node][i] = -1;
            }
        }
    }
}
void solve (){
    for(int i = 0; i < N; i++) for(int j = 0; j < 26; j++) tx[i][j] = ty[i][j] = -1;
    int q;
    cin >> q;
    while(q--){
        int op; string s;
        cin >> op >> s;
        if(op == 1){
            chx(s);
            addx(s);
        }
        else {
            if(chy(s)) addy(s);
        }
        cout << ans << "\n";
    }
    
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}