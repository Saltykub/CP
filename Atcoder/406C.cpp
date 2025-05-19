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
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<ll> cal;
    for(int i = 0; i < n; i++) cin >> arr[i];
    int cnt = 0;
    for(int i = 0; i < n-1; i++){
        if(arr[i] < arr[i+1]) cnt++;
        else {
            if(cnt!=0) cal.pb(cnt);
            cnt = 0;
        }
    }
    if(cnt != 0) cal.pb(cnt);
    ll ans = 0;
    if(cal.size() >= 2){
        for(int i = 0; i < cal.size()-1; i++){
            ans += cal[i] * cal[i+1];
        }
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