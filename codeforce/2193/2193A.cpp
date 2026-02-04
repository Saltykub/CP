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
    int n,x,s;
    cin >> n >> s >> x;
    vll v(n);
    for(auto &u:v) cin >> u;
    ll sm = accumulate(all(v),0);
    if(sm > s || (s-sm)%x){
        cout << "No\n";
    }
    else {
        cout << "Yes\n";
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