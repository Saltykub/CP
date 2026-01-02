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
    int n;
    cin >> n;
    vector<pii> v(n);
    for(auto &[w,p]:v) cin >> w >> p;
    sort(all(v),[&](pii a, pii b){
        return (a.st+a.nd) < (b.st+b.nd);
    });
    ll sm = 0, cur = 0;
    for(auto [w,p]:v) sm += p;
    for(int i = 0; i < n; i++){
        cur += v[i].st + v[i].nd;
        if(cur > sm){
            cout << i << "\n";
            return;
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