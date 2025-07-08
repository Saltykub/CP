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
    vector<int> arr(n);
    int ans = 0;
    map<int,int> mp;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(auto u:arr) mp[u]++;
    sort(arr.begin(),arr.end());
    for(auto u:arr){
        if(mp[u]){
            mp[u]--;
            if(mp[k-u]){
                ans++;
                mp[k-u]--;
            }
        }
    }
    cout << ans << "\n";
    
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}