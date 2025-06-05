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
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> dp(513,INT_MAX); // dp[i] = smallest number that make i;
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        vector<int> ndp(dp);
        for(int j = 0; j <= 512; j++){
            if(dp[j] != INT_MAX){
                if(arr[i] > dp[j]){
                    ndp[arr[i]^j] = min(ndp[arr[i]^j],arr[i]); 
                }
            }
        }
        dp = move(ndp);
    }
    vector<int> ans;
    for(int i = 0; i <= 512; i++) if(dp[i] != INT_MAX) ans.pb(i);
    cout << ans.size() << "\n";
    for(auto u:ans) cout << u << " ";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}