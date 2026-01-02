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
void solve (){
    int n,q;
    cin >> n >> q;
    vll v(n), idx(n+1);
    for(auto &u:v) cin >> u;
    for(int i = 0; i < n; i++) idx[v[i]] = i+1;
    int cur = 0;
    int ret = 1;
    for(int i = 1; i <= n; i++){
        if(idx[i] < cur){
            ret++;
        }
        cur = idx[i];
    }
    while(q--){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        if()
        swap(v[a],v[b]);
        cout << ret << "\n";
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