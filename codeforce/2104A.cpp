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
    ll a,b,c;
    cin >> a >> b >> c;
    ll use = a + b + c;
    if(use%3 != 0){
        cout << "NO\n";
        return;
    } 
    use/=3;
    if(use - a + use - b == c - use && c - use != 0 && use-a >= 0 && use-b >= 0) cout << "YES\n";
    else cout << "NO\n";

}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}