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
    for(int i = 1; i <= n; i++){
        string ans = "";
        for(int j = 0; j < 11; j++){
            if((1<<j)&i) ans += "ed";
            else ans += "fE";
        }
        cout << ans << "\n";
    }
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    freopen("hash.in","r",stdin);
    freopen("hash.out","w",stdout);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}