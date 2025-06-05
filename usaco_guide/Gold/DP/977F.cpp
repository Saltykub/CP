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
    map<int,int> dp;
    vector<int> arr(n);
    int ans = 0, last = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        dp[arr[i]] = dp[arr[i]-1] + 1;
        if(dp[arr[i]] > ans){
            ans = dp[arr[i]];
            last = arr[i];
        }
    }
    cout << ans << "\n";
    vector<int> path;
    for(int i = n-1; i >= 0; i--){
        if(last == arr[i]){
            path.pb(i+1);
            last--;
        }
    }
    reverse(path.begin(),path.end());
    for(auto u:path) cout << u << " ";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}