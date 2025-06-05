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
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &x:arr) cin >> x;
    ll sm = accumulate(arr.begin(),arr.end(),0LL);
    ll ans = 0;
    for(auto u:arr){
        sm-=u;
        ans += u*sm;
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