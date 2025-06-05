#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
bool CASE = false;
ll power[10];
void solve (){
    ll ans = 0;
    for(int i = 0; i < 9; i++){
        int x;
        cin >> x;
        x--;
        ans += x*pow(9,i);
    }
    int sa[12] = {0,1,3,4,6,7,0,3,1,4,2,5};
    int sb[12] = {1,2,4,5,7,8,3,6,4,7,5,8};
    vector<int> permu;
    for(int i = 0; i <= 9; i++) power[i] = pow(9,i);
    for(int i = 0; i < 9; i++) permu.pb(i);
    vector<bool> vis(power[9],false);
    ll init = 0;
    for(int i = 0; i < 9; i++) init += permu[i]*power[i];
    queue<pii> q;
    q.push({init,0});
    vis[init] = true;
    while(!q.empty()){
        auto [state,cur] = q.front();
        q.pop();
        if(state == ans){
            cout << cur;
            return;
        }
        for(int i = 0; i < 12; i++){
            ll nxt = state;
            int a = nxt%power[sa[i]+1] / power[sa[i]];  
            int b = nxt%power[sb[i]+1] / power[sb[i]];
            nxt += a*power[sb[i]] - a*power[sa[i]] + b*power[sa[i]] - b*power[sb[i]];
            if(!vis[nxt]){
                q.push({nxt,cur+1});
                vis[nxt] = true;
            }
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