#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    int n,h,l;
    cin >> n >> h >> l;
    vll v(n);
    for(auto &u:v) cin >> u;
    vll tmp;
    for(auto u:v){
        if(u <= max(h,l)) tmp.pb(u);
    }
    sort(all(tmp));
    int sz = sz(tmp);
    int j = sz-1;
    int ans = 0;
    for(int i = 0; i < sz; i++){
        if(j < 0 || i >= j) break;
        if(tmp[i] <= min(h,l) && tmp[j] <= max(h,l)) {
            j--;
            ans++;
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