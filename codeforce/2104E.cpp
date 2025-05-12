#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 1e6+1;
int dp [N];
ll mx [26];
vector<int> posi[26];
bool CASE = false;
void solve (){
    ll n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++){
        posi[s[i]-'a'].pb(i);
    }
    for(int i = n-1; i >= 0; i--){
        ll mn = INT_MAX;
        for(int j = 0; j < k; j++){
            mn = min(mx[j],mn);
        }
        dp[i] = mn+1;
        mx[s[i]-'a'] = dp[i];
    }
    int q;
    cin >> q;
    while(q--){
        string t;
        cin >> t;
        int l = -1;
        bool pass = false;
        for(int i = 0; i < t.size(); i++) {
            int c = t[i]-'a';
            auto it = upper_bound(posi[c].begin(),posi[c].end(),l);
            if(it == posi[c].end()) {
                cout << 0 << "\n";
                pass = true;
                break;
            }
            else l = *it;
        }
        if(pass) continue;
        cout << dp[l] << "\n";
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