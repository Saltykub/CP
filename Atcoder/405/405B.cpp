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
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    vector<int> cnt(m+1);
    int all = 0;
    for(auto &x:arr){
        cin >> x;
        cnt[x]++;
        if(cnt[x] == 1) all++;
    }
    int ans = 0;
    reverse(arr.begin(),arr.end());
    if(all < m) {
        cout << ans;
        return;
    }
    for(auto u:arr){
        cnt[u]--;
        ans++;
        if(cnt[u] == 0) {
            cout << ans;
            return;
        }
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