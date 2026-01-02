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
    int n,m;
    cin >> n >> m;
    vector<int> cnt(m+1,0);
    vector<vector<int>> sub;
    for(int i = 0; i < n; i++){
        int l;
        cin >> l;
        vector<int> tmp(l);
        for(auto &u:tmp) cin >> u;
        sub.pb(tmp);
    }
    for(auto s:sub){
        for(auto val:s){
            cnt[val]++;
        }
    }
    int ans = 1;
    bool ch = true;
    for(int i = 1; i <= m; i++){
        if(cnt[i] == 0) {
            cout << "No\n";
            return;
        }
    }
    for(auto s:sub){
        bool can = true;
        for(auto val:s){
            if(cnt[val]-1 == 0) can = false;
        }
        if(can) ans++;
    }
    if(ans >= 3) cout << "Yes\n";
    else cout << "No\n";

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}