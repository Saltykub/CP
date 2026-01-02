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
bool CASE = false;
ll nxt[N], cycle[N], vis[N], leave[N];
vll pre[N];
void floyd(int s){
    int fast = s, slow = s;
    fast = nxt[nxt[fast]];
    slow = nxt[slow];
    while(slow != fast){
        fast = nxt[nxt[fast]];
        slow = nxt[slow];
    }
    fast = s;
    while(fast != slow){
        fast = nxt[fast];
        slow = nxt[slow];
    }
    cycle[fast] = 1;
    int tmp = fast;
    while(true){
        tmp = nxt[tmp];
        cycle[tmp] = 1;
        if(tmp == fast) break;
    }
    return;
}
void solve (){
    int n,q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        nxt[i] = x;
        pre[x].pb(i);   
        if(i != x) leave[x]++;
    }
    for(int i = 1; i <= n; i++){
        if(!leave[i]) {
            floyd(i);
        }
        if(cycle[i]){
            queue<pii> q;
            q.push({i,0});
            while(!q.empty()){
                auto[node,cur] = q.front();
                q.pop();
                for(auto u:adj[node]){
                    if(!cycle[u]){
                        dis[u] = cur+1;
                    }
                }
                
            }
        }
    }
    while(q--){

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