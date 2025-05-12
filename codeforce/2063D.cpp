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
    ll n,m;
    cin >> n>> m;
    vector<ll> a(n),b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    ll k = 0;
    if(n < m) {
        swap(n,m);
        swap(a,b);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<int> ans(n+1,0);
    ll la = 0, ra = n-1, lb = 0, rb = m-1;
    // can ans[1] t0 ans m/3
    deque<int> sma,smb;
    for(int i = 1; i <= n; i++){
        ans[i]+=ans[i-1];
        if(lb > rb){
            ans[i] -= smb.back();
            smb.pop_back();
            if(la+1 >= ra-1) break;
            ans[i] += a[ra--]-a[la++];
            ans[i] += a[ra]-a[la];
            k++;
            continue;
        }
        else if(la > ra){
            ans[i] -= sma.back();
            sma.pop_back(); 
            if(lb+1 >= rb-1) break;
            ans[i] += b[rb--]-b[lb++];
            ans[i] += b[rb]-b[lb];
            k++;
            continue;
        }
        ll cala = a[ra]-a[la], calb = b[rb]-b[lb];
        if(cala == calb && cala == 0) break;
        if(cala > b[rb]-b[lb]){
            ans[i]+=cala;
            sma.pb(cala);
            la++;
            ra--;
        }
        else {
            ans[i]+=calb;
            smb.pb(calb);
            lb++;
            rb--;
        }
        k++;
    }
    cout << k << "\n";
    for(int i = 1; i <= k; i++) cout << ans[i] << " ";
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}