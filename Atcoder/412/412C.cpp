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
    int n;
    cin >> n;
    vector<ll> v(n-2);
    ll f,e;
    cin >> f;
    for(auto &u:v) cin >> u;
    cin >> e;
    sort(v.begin(),v.end());
    int ans = 2;
    ll nxt = -1;
    for(int i = 0; i < v.size(); i++){
        if(2*f >= e){
            cout << ans << "\n";
            return;
        }
        if(v[i] <= 2*f){
            nxt = v[i];
        }
        else {
            f = nxt;
            ans++;
            if(v[i] <= 2*f){
                nxt = v[i];
            }
        }
         if(2*nxt >= e){
            cout << ans+1 << "\n";
            return;
        }
    }
    if(2*f >= e){
        cout << ans << "\n";
        return;
    }
    cout << -1 << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}