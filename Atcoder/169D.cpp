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
    ll n;
    cin >> n;
    ll cnt = 0,ans = 0;
    ll sn = sqrt(n);
    vector<ll> v;
    for(int i = 2; i <= sn; i++){
        cnt = 0;
        while(n%i == 0){
            n/=i;
            cnt++;
        }
        if(cnt) v.pb(cnt);
    }
    if(n!=1) v.pb(1);
    for(auto u:v){
        int j = 1;
        //cout << u << " ";
        while(u >= j){
            u-=j;
            ans++;
            j++;
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