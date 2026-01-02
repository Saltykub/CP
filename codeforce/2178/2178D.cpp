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
bool CASE = true;
void solve (){
    int n,m;
    cin >> n >> m;
    vll v(n);
    for(auto &u:v) cin >> u;
    if(m > n/2) {
        cout << -1 << "\n";
    }
    else {
        vector<pii> p;
        for(int i = 0; i < n; i++){
            p.pb({v[i],i+1});
        }
        sort(all(p));
        vector<pii> ans;
        if(m != 0){
            for(int i = 0; i < n-2*m; i++){
               ans.pb({p[i].nd,p[i+1].nd});
            }
            for(int i = n-2*m; i < n; i+=2){
                ans.pb({p[i+1].nd,p[i].nd});
            }
            cout << ans.size() << "\n";
            for(auto [x,y]:ans){
                cout << x << " " << y << "\n";
            }
        }
        else {
            ll sm = 0, idx = -1;
            for(int i = n-2; i >= 0; i--){
                sm += p[i].st;
                if(sm >= p[n-1].st){
                    idx = i;
                    break;
                }
            }
            if(idx == -1){
                cout << -1 << "\n";
                return;
            }
            for(int i = 0; i < idx; i++){
                ans.pb({p[i].nd,p[i+1].nd});
            }
            for(int i = idx; i <= n-3; i++){
                ans.pb({p[i].nd,p[n-1].nd});
            }
            ans.pb({p[n-1].nd,p[n-2].nd});
            cout << ans.size() << "\n";
            for(auto [x,y]:ans){
                cout << x << " " << y << "\n";
            }
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