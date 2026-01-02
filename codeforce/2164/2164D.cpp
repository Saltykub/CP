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
    int n,k;
    cin >> n >> k;
    string s,t;
    cin >> s >> t;
    vector<int> mp[26];
    vll target(n);
    for(int i = 0; i < s.size(); i++){
        mp[s[i]-'a'].pb(i);
    }
    ll mx = 0;
    int prev = n;
    for(int i = n-1; i >= 0; i--){
        int c = t[i]-'a';
        auto it = upper_bound(all(mp[c]),prev) - mp[c].begin() -1;
        if(it == -1){
            cout << -1 << "\n";
            return;
        }
        target[i] = i-mp[c][it];
        prev = min(i-1, mp[c][it]);
        mx = max(target[i],mx);
    }
    if(mx > k) {
        cout << -1 << "\n";
        return;
    }
    cout << mx << "\n";
    string cur = s;
    for(int i = 0; i < mx; i++){
        string tmp = cur;
        for(int j = 0; j < n; j++){
            if(target[j] == i) cur[j] = t[j];
            else if(target[j] > i) cur[j] = tmp[j-1];
        }
        cout << cur << "\n";
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