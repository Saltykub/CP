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
    vector<int> v(n+1);
    for(int i = 0; i < m; i++){
        int l,r;
        cin >> l >> r;
        l--,r--;
        v[l]++;
        v[r+1]--;
    }
    vector<pii> cal;
    cal.pb({v[0],0});
    for(int i = 1; i < n; i++){
        v[i]+=v[i-1];
        cal.pb({v[i],i});
    }
    sort(cal.begin(),cal.end(),greater<pii>());
    vector<int> ans(n);
    int cur = 0;
    if(cal[0].st == n) cur++;
    for(auto [val,idx]:cal){
        ans[idx] = cur++;
    }
    for(auto u:ans) {
        if(u == n) cout << 0 << " ";
        else cout << u << " ";
    }
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