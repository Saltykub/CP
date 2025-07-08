#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
const ll MOD = 1e9;
bool CASE = false;
void solve (){
    int n,k;
    cin >> n >> k;
    if(n < k) cout << 1;
    else {
        deque<ll> dq;
        for(int i = 0; i < k; i++) dq.push_back(1);
        ll prev = k;
        for(int i = k; i <= n; i++){
            dq.push_back(prev);
            prev -= dq.front();
            dq.pop_front();
            prev += dq.back();
            prev %= MOD;
        }
        cout << ((dq.back()%MOD)+MOD)%MOD;
    }

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}