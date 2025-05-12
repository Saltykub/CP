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
    int n,x;
    cin >> n >> x;
    int sm = 0;
    for(int i = 0; i < n; i++) {
        int w;
        cin >> w;
        sm+=w;
    }
    if(x*n == sm) cout << "YES\n";
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