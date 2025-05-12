#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int mod = 1e9+7;
void solve(){
    int n,k;
    cin >> n >> k;
    vector<ll> light(n);
    for(int i = 0; i < n; i++) cin >> light[i];
    sort(light.begin(),light.end());
    ll l = light[n-1], r = light[n-1]+k-1;
    for(int i = 0; i < n-1; i++){
        if(int(floor(1.0*(light[n-1]-light[i])/k))%2){
            int shift = (light[n-1]-light[i])%k;
            if(shift)l = max(l,light[n-1] + k - shift);
            else l = INT_MAX;
        }
        else {
            int shift = (light[n-1]-light[i])%k;
            if(shift) r = min(r,light[n-1] + k - shift - 1);
        }
    }
    //cout << l << " " << r;
    if(l <= r) cout << l;
    else cout << -1;
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    // t=1;
    while(t--)
    {
        solve();
    }
}