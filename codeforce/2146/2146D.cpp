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
    ll l,r;
    cin >> l >> r;
    vector<ll> ans(r-l+1,-1);
    ll sm = 0;
    for(int i = r; i >= l; i--){
        if(ans[i-l] != -1) {
            sm += ans[i-l]|i;
            continue;
        }
        for(int j = 32; j >= 0; j--){
            if((1LL<<j)&i){
                ll target = (1LL<<(j+1))-1;
                target ^= i;
                if(target > r || target < l) continue;
                ans[target-l] = i;
                ans[i-l] = target;      
                break;      
            }
        }
        if(ans[i-l] == -1) ans[i-l] = i;
        sm += ans[i-l]|i;
    }
    cout << sm << "\n";
    for(auto u:ans) cout << u << " ";
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