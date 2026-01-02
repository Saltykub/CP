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
bool CASE = false;
void solve (){
    ll n,m;
    cin >> n >> m;
    set<pii> s;
    int ans = 0;
    while(m--){
        int r,c;
        cin >> r >> c;
        if(s.count({r,c}) || s.count({r+1,c}) || s.count({r,c+1}) || s.count({r+1,c+1})) continue;
        ans++;
        s.insert({r,c});
        s.insert({r+1,c});
        s.insert({r,c+1});
        s.insert({r+1,c+1});
    }
    cout << ans;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}