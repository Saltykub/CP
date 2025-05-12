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
    int n,q;
    cin >> n >> q;
    vector<ll> arr(n+2), qs(n+2);
    for(int i = 1; i <= n; i++) cin >> arr[i];
    while(q--){
        int l,r;
        cin >> l >> r;
        qs[l]++;
        qs[r+1]--;
    }
    for(int i = 1; i <= n; i++) qs[i]+=qs[i-1];
    sort(qs.begin(),qs.end());
    sort(arr.begin(),arr.end());
    ll ans = 0;
    for(int i = 0; i <= n+1; i++){
        ans+= qs[i]*arr[i];
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