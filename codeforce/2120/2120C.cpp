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
    ll n,m;
    cin >> n >> m;
    if(m < n || m > n*(n+1)/2){
        cout << -1 << "\n";
        return;
    }
    ll cur = 1;
    vector<pii> ans;
    for(int i = n; i >= 1; i--){
        if(m-i <= 0) {
            ans.pb({cur,m});
            break;
        }
        ans.pb({cur,i});
        m-=i;
        cur++;
    }
    ll sz = ans.size();
    ll root = ans[sz-1].st;
    cout << root << "\n";
    reverse(ans.begin(),ans.end());
    vector<int> v;
    v.pb(ans[0].nd-1);
    for(int i = 1; i < sz; i++){
        v.pb(ans[i].nd-ans[i-1].nd-1);
    }
    int j = n, start = root;
    for(auto u:v){
        for(int i = 0; i < u; i++){
            cout << j << " " << start << "\n";
            j--;
        }
        start--;
    }
    for(int i = 1; i < root; i++){
        cout << i << " " << root << "\n";
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