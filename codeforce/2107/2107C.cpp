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
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> v(n);
    for(auto &x:v) cin >> x;
    ll mx = 0, cur = 0;
    int j = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
           mx = max(mx,cur);
           cur = 0;
        }
        else {
            cur += v[i];
            if(cur < 0) cur = 0;
            mx = max(mx,cur);
        }
    }
    if(mx > k) cout << "No\n";
    else {
        bool can = false;
        for(int i = 0; i < n; i++){
            if(s[i] == '0') can = true;
        }
        if(!can && mx != k){
            cout << "No\n";
            return;
        }
        ll cur1 = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                ll mx1 = cur1;
                for(int j = i+1; j < n; j++){
                    if(s[j] == '0'){
                        v[i] = k-mx1;
                        s[i] = '1';
                        break;
                    }
                    cur1 += v[j];
                    mx1 = max(cur1,mx1);
                }
                if(s[i] == '0'){
                    v[i] = k-mx1;
                    s[i] = '1';
                }
                break;
            }
            cur1 += v[i];
            if(cur1 < 0) cur1 = 0;
        }
        for(int i = 0; i < n;i++) if(s[i] == '0') v[i] = -1e18;
        cout << "Yes\n";
        for(auto u:v) cout << u << " ";
        cout << "\n";
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