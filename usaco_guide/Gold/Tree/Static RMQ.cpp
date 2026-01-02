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
bool CASE = false;
ll st[30][N];
void solve (){
    ll n,q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        st[0][i] = x;
    }
    for(int i = 1; i < 30; i++){
        for(int j = 0; j + (1<<i)-1 < n; j++){
            st[i][j]  = min(st[i-1][j],st[i-1][j+(1LL<<(i-1))]);
        }
    }
    while(q--){
        int l,r;
        cin >> l >> r;
        r--;
        l--;
        int lg = log2(r-l+1);
        cout << min(st[lg][l],st[lg][r-(1<<lg)+1]) << "\n";
    }
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}