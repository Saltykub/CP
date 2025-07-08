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
    int l,n;
    cin >> n >> l;
    vector<ll> cnt(l,0);
    cnt[0]++;
    int cur = 0;
    ll ans = 0;
    for(int i = 0; i < n-1; i++){
        ll d;
        cin >> d;
        cur += d;
        cur%=l;
        cnt[cur]++;
    }
    int third = l/3;    
    if(l%3) {
        cout << 0;
        return;
    }
    for(int i = 0; i < l; i++){
        if(i+2*third < l){
            ans += cnt[i] * cnt[i+third] * cnt[i+2*third];
        }
        else break;
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