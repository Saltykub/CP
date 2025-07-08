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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int z = 0, o = 0;
    for(auto u:s) {
        if(u == '0') z++;
        else o++;
    }
    if(z%2) {
        z--;
        o--;
    }
    z/=2;
    o/=2;
    if(o > z) swap(o,z);
    int mx = z+o;
    bool can = false;
    while(true){
        if(mx == k) can = true;
        if(o == 0) break;
        mx-=2;
        o-=1;
    }
    if(can) cout << "YES\n";
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