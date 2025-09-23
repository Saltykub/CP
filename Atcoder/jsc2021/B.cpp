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
    int n,m;
    cin >> n >> m;
    vector<int> a(n),b(m);
    set<int> sa,sb,ans;
    for(auto &x:a) cin >> x, sa.insert(x);
    for(auto &x:b) cin >> x, sb.insert(x);
    for(auto u:a) if(sb.find(u) == sb.end()) ans.insert(u);
    for(auto u:b) if(sa.find(u) == sa.end()) ans.insert(u);
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