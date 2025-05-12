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
    vector<ll> v(n+1),l(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    ll mxl = v[1]+1;
    l[1] = mxl;
    for(int i = 2; i <= n; i++){
        ll temp = v[i]+i;
        l[i] = v[i]+mxl;
        mxl = max(mxl,temp);
    }
    ll mxr = v[n]-n, ans = 0;
    for(int i = n-1; i >=1; i--){
        ll temp = v[i]-i;
        ans = max(ans,l[i]+mxr);
        mxr = max(mxr,temp);
    }
   // for(int i = 0; i <= n; i++) cout << l[i] << " ";
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