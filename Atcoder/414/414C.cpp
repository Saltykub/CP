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
    vector<string> s[13];
    s[0].pb("");
    for(int i = 0; i <= 9; i++) s[1].pb(to_string(i));
    for(int i = 2; i <= 12; i++){
        for(auto u:s[i-2]){
            for(int j = 0; j <= 9; j++){
                s[i].pb(to_string(j)+u+to_string(j));
            }
        }
    }
    ll a,n;
    cin >> a >> n;
    ll ans = 0;
    for(int i = 1; i <= 12; i++){
        for(auto u:s[i]){
            ll x = stoll(u);
            if(x > n || u[0] == '0') continue;
            string ch = "";
            while(x){
                ll mod = x%a;
                ch += to_string(mod);
                x/=a;
            }
            string rev = ch;
            reverse(rev.begin(),rev.end());
            if(ch == rev){
                ans += stoll(u);
            } 
        }
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