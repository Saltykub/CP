#include<bits/stdc++.h>
#define ll long long
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb emplace_back
using namespace std;
void solve (){
    ll n,m;
    cin >> n >> m;
    ll sm = 0;
    for(int i = 0; i < 30; i++){
        ll mod = int(pow(2,i));
        if(~((1<<i)&n)){
            if(m >= n%mod){
                sm+=n%mod;
            }
        }
    }
    cout << sm+n << "\n";
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