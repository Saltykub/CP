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
    vector<int> cnt(4*n+1,0);
    for(auto u:v) cnt[u]++;
    vector<int> qs(4*n+1,0);
    for(int i = 1; i <= 4*n; i++){
        qs[i]+=cnt[i];
        qs[i]+=qs[i-1];
    }
    int ans = 1;
    for(int i = 1; i <= n; i++){
        if(n-cnt[i]-cnt[2*i]-cnt[3*i]-(qs[4*n]-qs[4*i-1]) <= k){
            ans = i;
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