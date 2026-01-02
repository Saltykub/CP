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
    for(int i = 0; i < 32; i++){
        int cnt = 0;
        if((1LL<<i)&a) cnt++;
        if((1LL<<i)&b) cnt++;
        if((1LL<<i)&c) cnt++;
        if(cnt == 2){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}