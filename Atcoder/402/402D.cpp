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
    map<pii,int> mp;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        int pl = a-1;
        b+=pl;
        b%=n;
        if(b==0) b = n;
        mp[{1,b}]++;
    }
    ll ans = 0;
    for(auto u:mp){
        ans += (m-u.nd)*u.nd;
    }
    cout << ans/2 << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}