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
    int n;
    cin >> n;
    vector<int> v(n);
    map<int,vector<int>> mp;
    for(auto &u:v) cin >> u;
    int cur = 1;
    for(int i = 0; i < n; i++) mp[v[i]].pb(i);
    for(int i = 1; i <= n; i++){
        if(mp[i].size() > 0){
            if(mp[i].size()%i == 0){
                int cnt = 0;
                for(int j = 0; j < mp[i].size(); j++){
                    if(cnt < i){
                        v[mp[i][j]] = cur;
                        cnt++;
                    }
                    else {
                        cnt = 1;
                        cur++;
                        v[mp[i][j]] = cur;
                    }
                }
                cur++;
            }
            else {
                cout << -1 << "\n";
                return;
            }
        }
    }
    for(auto u:v) cout << u << " ";
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