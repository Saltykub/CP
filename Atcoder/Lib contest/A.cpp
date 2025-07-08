#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
vector<int> p(N);
int fp(int n){ return p[n] == n ? n : p[n] = fp(p[n]);}

void init(int n) { for(int i = 1; i <= n; i++) p[i] = i;}

void merge(int u,int v){
    int pu = fp(p[u]), pv = fp(p[v]);
    if(pu != pv){
        p[pu] = pv;
    }
}
void solve (){
    int n,q;
    cin >> n >> q;
    init(n);
    while(q--){
        int t,u,v;
        cin >> t >> u >> v;
        if(t == 1){
            cout << (fp(u) == fp(v)) << "\n";
        }
        else {
            merge(u,v);
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