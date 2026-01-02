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
    int n;
    cin >> n;
    vll v(n);
    for(auto &u:v) cin >> u;
    vll e, o;
    for(auto u:v){
        if(u%2) o.pb(u);
        else e.pb(u);
    }
    sort(all(o),greater<ll>());
    sort(all(e),greater<ll>());
    for(int i = 1; i < e.size(); i++) e[i] += e[i-1];
    for(int i = 1; i <= n; i++){
        if(o.empty()){
            cout << 0 << " ";
            continue;
        }
        if(e.empty()){
            if(i%2){
                cout << o[0] << " ";
            }
            else cout << 0 << " ";
            continue;
        }
        if(i <= e.size()+1){
            if(i == 1) cout << o[0] << " ";
            else cout << o[0] + e[i-2] << " ";
        }
        else {
            if(o.size()%2 == 0 && i == n){
                cout << 0 << " ";
                continue;
            }
            if(e.size() == 1){
                if(i%2 == 0) cout << o[0] + e[0] << " ";
                else cout << o[0] << " ";
            }
            if(e.size() == 2){
                if(i%2) cout << o[0] + e[1] << " ";
                else cout << o[0] + e[0] << " ";
            }
            if(e.size() >= 3){
                if(i%2 == (e.size()+1)%2) cout << o[0] + e[e.size()-1] << " ";
                else cout << o[0] + e[e.size()-2] << " ";
            }
        }
    }
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}