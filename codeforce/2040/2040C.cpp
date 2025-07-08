#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
ll bpow(ll a,ll b){
    if(b == -1) return 0;
    if(b == 0) return 1;
    ll ret = bpow(a,b/2);   
    if(b%2) return ret*ret*a;
    return ret*ret;
}
void solve (){
    ll n,k;
    cin >> n >> k;
    if(n <= 60 && k > bpow(2,n-1) ) {
        cout << -1 << "\n";
        return;
    }
    vector<int> ans(n);
    ll l = 0, r = n-1;
    ll nn = n-2;
    ll cur = 1;
   while(l!=r){
        if(nn <= 60 && k > bpow(2,nn)){
            ans[r] = cur;
            k-=bpow(2,nn);
            r--;
        }
        else {
            ans[l] = cur;
            l++;
        }
        cur++;
        nn--;
    }
    ans[l] = cur;
    for(auto u:ans) cout << u << " ";
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