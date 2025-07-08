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
    int n;
    string s;
    cin >> n >> s;
    char t = '0';
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(t != s[i]) ans++;
        t = s[i];
    }
    if(ans >= 3) {
        ans -= 2;
    }
    else if(ans == 2){
        ans--;
    }
    cout << ans + n << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}