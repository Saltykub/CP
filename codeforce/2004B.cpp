#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
void solve (){
   int l,r,L,R;
   cin >> l >> r >> L >> R;
   int ans = min(r,R) - max(l,L);
   if(l != L) ans ++;
   if(r != R) ans ++;
   if(r < L || R < l) ans = 1;
   cout << ans << "\n";
   
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