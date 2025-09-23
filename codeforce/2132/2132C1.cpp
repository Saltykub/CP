#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
ll price[32];
void precom(){
    price[0] = 3;
    for(int i = 1; i < 32; i++){
        price[i] = pow(3,i+1) + i*pow(3,i-1);
    }
}
void solve (){
    ll n, k;
    cin >> n >> k;
    vector<ll> s;
    while(n){
        s.pb(n%3);
        n/=3;
    }
    ll ans = 0, cnt = 0;
    for(int i = 0; i < s.size(); i++) cnt += s[i];
    if(cnt > k){
        cout << -1 << "\n";
    }
    else {
        k -= cnt;
        for(int i = s.size()-1; i > 0; i--){
           if(k >= 2){
               s[i-1]+=min(3*s[i],3*(k/2));
               if(k >= 2*s[i]){
                    k-=2*s[i];
                    s[i] = 0;
               }
               else {
                  s[i] -= k/2;
                  k = 0;
               }
           }
        }
        for(int i = 0; i < s.size(); i++){
            ans += price[i]*s[i];
        }
        cout << ans << "\n";
    }
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    precom();
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}