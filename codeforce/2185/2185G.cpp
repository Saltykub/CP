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
    vll v[n];
    ll allsz = 0;
    for(int i = 0; i < n; i++){
        int sz;
        cin >> sz;
        allsz+=sz;
        for(int j = 0; j < sz; j++){
            int x;
            cin >> x;
            v[i].pb(x);
        }
    }
    ll ans = 0,sm = 0;
    vll mex(n,0);
    map<ll,ll> cnt;
    for(int i = 0; i < n; i++){
        sort(all(v[i]));
        int sz = sz(v[i]);
        map<int,int> mp;
        vll tmp;
        for(auto u:v[i]) mp[u]++;
        int idx = sz;
        for(int j = 0; j <= sz; j++){
            if(!mp[j]) {
                idx = j;
                mex[i] = j;
                break;
            }
        }
        ans += idx;
        for(int j = idx+1; j <= sz+1; j++){
            if(!mp[j]){
                cnt[idx]+=j-mex[i];
                break;
            }
        }
    }
    for(int i = 0; i < n; i++){
        sort(all(v[i]));
        int sz = sz(v[i]);
        map<ll,ll> mp;
        vll tmp;
        for(auto u:v[i]) mp[u]++;
        for(auto [a,b]:mp){
            if(b == 1){
                if(mex[i] <= a){
                    sm += ans*(n-1);
                    sm += cnt[a];
                }
                else {
                    sm += (ans-mex[i]+a)*(n-1); 
                    sm += cnt[a];
                }
            }
            else {
                sm += ans*(n-1)*b;
                sm += cnt[a]*b;
            }
        }
        
    }
    cout << sm << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}