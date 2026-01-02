#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
int ask(int idx, int val){
    cout << "? " << idx << " " << val << endl;
    int ret;
    cin >> ret;
    return ret;
}
void solve (){
    int n;
    cin >> n;
    vector<int> tmp;
    for(int i = 1; i <= n-1; i++) tmp.pb(i);
    int mx = 0;
    for(int i = 0; i <= n; i++){
        if((1LL<<i) >= n){
            mx = i;
            break;
        }
    }
    vector<int> cnt(mx+1,0);
    set<int> s;
    for(int i = 1; i <= n; i++){
        s.insert(i);
        for(int j = 0; j <= mx; j++){
            if((1LL<<j)&i) cnt[j]++;
        }
    }
    ll ans = 0;
    for(int i = 0; i <= mx; i++){
        vector<int> o,z;
        for(auto u:tmp){
            if(ask(u,(1<<i))) o.pb(u);
            else z.pb(u);
        }
        if(o.size() < cnt[i]){
            ans += (1<<i);
            swap(tmp,o);
            vector<int> t;
            for(auto u:s){
                if((1<<i)&u) continue;
                for(int j = i+1; j <= mx; j++){
                    if((1<<j)&u) cnt[j]--;
                }
                t.pb(u);
            }
            for(auto u:t) s.erase(u);
        }
        else {
            swap(tmp,z);
             vector<int> t;
            for(auto u:s){
                if((1<<i)&u) {
                    for(int j = i+1; j <= mx; j++){
                        if((1<<j)&u) cnt[j]--;
                    }
                    t.pb(u);
                }
               
            }
            for(auto u:t)s.erase(u);
        }

    }
    cout << "! " << ans << endl;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}