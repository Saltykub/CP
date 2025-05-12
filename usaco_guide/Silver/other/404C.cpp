#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
    int n,k;
    cin >> n >> k;
    vector<int> d(n+1);
    for(int i = 1; i <= n; i++) cin >> d[i];
    vector<int> lv[n+1];
    for(int i = 1; i <= n; i++){
        lv[d[i]].pb(i);
    }
    bool can = true;
    vector<pii> ans;
    if(lv[0].size() != 1) can = false;
    for(int i = 1; i < n; i++){
        if(i == 2) k--;
        if(lv[i-1].size() == 0 && lv[i].size() != 0){
            can = false;
            break;
        } 
        else if(lv[i].size() == 0) continue;
        else {
            if(ceil(1.0*(lv[i].size())/lv[i-1].size()) > k) {
                can = false;
                break;
            }
            int cur = 0, j = 0;
            for(auto u:lv[i]){
                ans.pb({lv[i-1][j],u});
                cur++;
                if(cur == k){
                    cur = 0;
                    j++;
                }
            }
        }
    }
    if(!can) {
        cout << -1 << "\n";
        return;
    }
    cout << ans.size() << "\n";
    for(auto u:ans){
        cout << u.st << " " << u.nd << "\n";
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