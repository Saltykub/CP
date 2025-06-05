#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
vector<int> p(N), compo(N,1);
int fp(int node){
    if(p[node] == node) return node;
    return p[node] = fp(p[node]);
}
void solve (){
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) p[i] = i;
    int cnt = n;
    int mx = 0;
    while(m--){
        int a,b;
        cin >> a >> b;
        int pa = fp(a), pb = fp(b);
        if(pa == pb) {
            cout << cnt << " " << mx << "\n";
        }
        else {

            if(compo[pa] < compo[pb]){
               swap(pa,pb);
            }
             p[pb] = pa;
             compo[pa] += compo[pb];
             cnt--;
             mx = max(compo[pa],mx);
             cout << cnt << " " << mx << "\n";
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