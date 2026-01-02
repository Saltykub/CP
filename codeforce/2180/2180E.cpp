#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    ll l,r;
    cin >> l >> r;
    ll ret = 1;
    // 0 1 
    // 1 0
    if(l == 1){
        bool can = true;
        int lo = log2(r);
        if(pow(2,lo) == r) cout << 1;
        else cout << 0;
        cout << "\n";
        return;
    }
    for(int i = 1; i <= 60; i++){
        ll cal = pow(2,i);
        if(l%cal == 0 && r%cal == cal-1) ret *=2;
    }
    ret--;
    cout << ret << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}