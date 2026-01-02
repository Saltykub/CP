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
    vector<int> v(n);
    for(auto &u:v) cin >> u;
    int mx = v[0];
    ll ans = 0;
    for(int i = 1; i < n; i++){
        if(i%2){
            v[i] = max(v[i],mx);
        }
        mx = max(mx,v[i]);
        //cout << v[i] << " ";
    }
    if(v[0] >= v[1]){
        ans += abs(v[0]-v[1])+1;
    }
    for(int i = 1; i < n; i++){
        if(i%2 == 0){
            if(v[i] >= v[i-1]){
                //cout << v[i] << " " << v[i-1] << "\n";
                ans += abs(v[i]-v[i-1])+1;
                v[i] = v[i-1]-1;
            }
        }
    }
    cout << ans << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}