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
    vector<int> v(n),cnt(n+1);
    for(auto &u:v) {
        cin >> u;
        cnt[u]++;
    }
    int ans = 0;
    for(int i = 0; i < k; i++){
        if(cnt[i] == 0){
            ans++;
        }
    }
    ans = max(ans,cnt[k]);
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