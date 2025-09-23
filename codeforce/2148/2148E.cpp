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
    int n,k;
    cin >> n >> k;
    vector<int> v(n),cur(n+1,0);
    map<int,int> mp;
    for(auto &x:v) cin >> x, mp[x]++;
    for(auto [idx,val]:mp){
        if(val%k!=0) {
            cout << 0 << "\n";
            return;
        }
        mp[idx] = val/k;
    }
    ll ans = 0;
    int j = 0;
    for(int i = 0; i < n; i++){
        if(cur[v[i]] < mp[v[i]]){
            cur[v[i]]++;
            ans += i-j+1;
        }
        else {
            while(cur[v[i]] == mp[v[i]]){
                cur[v[j]]--;
                j++;
            }
            cur[v[i]]++;
            ans += i-j+1;
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