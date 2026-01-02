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
    ll n,x;
    cin >> n >> x;
    vll v(n);
    for(auto &u:v) cin >> u;
    ll cur = 0, sm = 0, mx = 0;
    set<int> s;
    vll ans;
    sort(v.begin(),v.end(),greater<ll>());
    for(int i = 0, j = n-1; i < n, i <= j; i++){
        if((sm+v[i])/x > cur){
            mx += v[i];
            sm += v[i];
            //cout << i << "\n";
            ans.pb(v[i]);
            s.insert(i);
            cur = sm/x;
        }
        else {
            while(i < j){
                sm += v[j];
                ans.pb(v[j]);
                s.insert(j);
                //cout << j << "\n";
                j--;
                if((sm + v[i])/x > cur){
                    mx += v[i];
                    sm += v[i];
                    s.insert(i);
                    //cout << i << "\n";
                    ans.pb(v[i]);
                    cur = sm/x;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < n; i++) if(!s.count(i)){
        ans.pb(v[i]);
    }
    cout << mx << "\n";
    for(auto u:ans) cout << u << " ";
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}