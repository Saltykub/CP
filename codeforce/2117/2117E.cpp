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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(auto &x:a) cin >> x;
    for(auto &x:b) cin >> x;
    vector<int> ida(n+1,-1), idb(n+1,-1);
    for(int i = 0; i < n; i++){
        ida[a[i]] = i;
        idb[b[i]] = i;
    }
    int ans = -1;
    for(int i = 0; i < n; i++){
        if(a[i] == b[i]) ans = i;
        if(idb[a[i]] != -1 && idb[a[i]] != i+1 && idb[a[i]] > i) ans = i;
        if(ida[b[i]] != -1 && ida[b[i]] != i+1 && ida[b[i]] > i) ans = i;
        if(ida[a[i]] > i) ans = i;
        if(idb[b[i]] > i) ans = i;
    }
    cout << ans+1 << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}