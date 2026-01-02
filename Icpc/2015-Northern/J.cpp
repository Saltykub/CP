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
    ll n,t;
    cin >> n >> t;
    vector<ll> p(n+1,0);
    vector<ll> d(n+1,0);
    for(int i = 1; i <= n-1; i++) cin >> p[i];
    for(int i = 2; i <= n-1; i++) cin >> d[i];
    ll l = 1, r = n-1;
    while(l < r){
        ll mid = (l+r)/2;
        multiset<ll> s;
        int j = 0;
        vector<ll> v;
        for(int i = 2; i <= 1+mid; i++){
            s.insert(d[i]);
            v.pb(d[i]);
        }
        for(int i =  mid+2; i < n; i++){
            ll mn = *s.begin();
            s.erase(s.find(v[j]));
            j++;
            v.pb(d[i]+mn);
            s.insert(d[i]+mn);
        }
        if(*s.begin() <= t-n+1) r = mid;
        else l = mid+1;
    }
    ll ret = LLONG_MAX;
    for(int i = l; i <= n-1; i++){
        ret = min(ret,p[i]);
    }
    cout << ret;
}
int main(){   
    // ios_base::sync_with_stdio(false);cin.tie(0);
    // freopen("journey.in","r",stdin);
    // freopen("journey.out","w",stdout);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}