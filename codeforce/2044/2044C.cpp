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
    ll m1,a,b,c;
    cin >> m1 >> a >> b >> c;
    ll m2 = m1,ans = 0;
    ans += min(m1,a);
    m1-=a;
    ans += min(m2,b);
    m2-=b;
    m1 = max(m1,0LL); m2 = max(m2,0LL);
    ans+=min(m1+m2,c);
    cout << ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}