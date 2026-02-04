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
void solve (){
    int n,m;
    cin >> n >> m;
    vll r(n+1);
    for(int i = 1; i <= n; i++) r[i] = n-1;
    while(m--){
        int a,b;
        cin >> a >> b;
        r[a]--;
        r[b]--;
    }
    for(int i = 1; i <= n; i++){
        if(r[i] < 3){
            cout << 0 << " ";
        }
        else {
            ll x = r[i];
            cout << x*(x-1)*(x-2)/6 << " ";
        }
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