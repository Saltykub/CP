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
    ll n,m;
    cin >> n >> m;
    vector<pii> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i].st >> p[i].nd;
    }
    ll w = m, h = m;
    for(int i = 1; i < n; i++) {
        w+=p[i].st;
        h+=p[i].nd;
    }
    cout << 2*(w+h) << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}