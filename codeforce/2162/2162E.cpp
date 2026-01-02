#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &u:v) cin >> u;
    set<int> s;
    set<int> ns;
    for(int i = 1; i <= n; i++) {
        s.insert(i);
    }
    for(auto u:v){
        if(s.count(u)){
            s.erase(u);
            ns.insert(u);
        }
    }
    if(s.size() == 0){
        for(int i = 0; i < k; i++){
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    else if(s.size() >= 2){
        vector<int> ans;
        for(auto u:s) ans.push_back(u);
        for(auto u:ns) ans.push_back(u);
        for(int i = 0; i < k; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    else {
        vector<int> ans;
        for(auto u:s) ans.push_back(u);
        for(auto u:ns){
            if(u == v[n-1]) continue;
            ans.pb(u);
        }
        ans.pb(v[n-1]);
        for(int i = 0; i < k; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
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