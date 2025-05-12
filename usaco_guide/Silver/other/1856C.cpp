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
    ll n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    ll l = 1, r = 1e9;
    auto cal = [&](int mid){
        for(int i = 0; i < n; i++){
            ll cnt = k;
            for(int j = i; j < n; j++){
                ll need = mid - (j-i);
                if(arr[j] >= need) return true;
                cnt -= need-arr[j];
                if(cnt < 0) break;
            }
        }
        return false;
    };
    while(l < r){
        ll mid = (l+r+1)/2;
        if(cal(mid)) l = mid;
        else r = mid-1;
        //cout << l << " " << r << "\n";
    } 
    cout << l << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}