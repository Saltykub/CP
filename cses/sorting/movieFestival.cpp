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
    int n;
    cin >> n;
    vector<pii> v(n);
    for(auto &[a,b]:v) cin >> b >> a;
    sort(all(v));
    int cur = 0;
    int ret = 0;
    for(auto [r,l]:v){
        if(l >= cur) {
            cur = r;
            ret++;
        }
    }
    cout << ret;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}