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
    int q;
    cin >> q;
    deque<pii> dq;
    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int c,x;
            cin >> c >> x;
            dq.push_back({c,x});
        }
        else {
            int k;
            cin >> k;
            int cnt = 0;
            ll ans = 0;
            while(true){
                if(cnt+dq.front().st <= k){
                    ans += dq.front().st*dq.front().nd;
                    cnt += dq.front().st;
                    dq.pop_front();
                }
                else {
                    auto [c,x] = dq.front();
                    dq.pop_front();
                    ans += (k-cnt)*x;
                    dq.push_front({c-(k-cnt),x});
                    cnt = k;
                }
                if(cnt == k) break;
            }
            cout << ans << "\n";
        }
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