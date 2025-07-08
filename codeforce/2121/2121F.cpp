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
    ll n,s,x;
    cin >> n >> s >> x;
    vector<int> v(n+1,0);
    for(int i = 1; i <= n; i++) cin >> v[i];
    bool can = false;
    ll ans = 0;
    int j = 1;
    for(int i = 1; i <= n; i++){
        if(v[i] == x){
            can = true;
        }
        if(v[i] > x){
            if(!can){
                j = i+1;
            }
            else {
                vector<ll> qs;
                qs.pb(0);
                for(int k = j; k <= i-1; k++){
                    qs.pb(v[k]);
                }
                int idx = 0, idx2 = 0;
                for(int k = 1; k < qs.size(); k++){
                    if(!idx && qs[k] == x) idx = k;
                    if(qs[k] == x) idx2 = k;
                    qs[k] += qs[k-1];
                }
                map<ll,ll> mp;
                for(int k = 1; k < qs.size(); k++){
                     mp[qs[k]]++;
                }
                bool go = true;
                for(int k = 1; k <= idx2; k++){
                    if(qs[k]-qs[k-1] == x){
                        go = true;
                    }
                    else if(go){
                        for(int kk = k; kk <= idx2; kk++){
                            if(qs[kk]-qs[kk-1] != x) mp[qs[kk]]--;
                            else break;
                        }
                        go = false;
                    }
                    ans+=mp[s+qs[k-1]];
                    if(qs[k]-qs[k-1] == x){
                        mp[qs[k]]--;
                    }
                }
                can = false;
                j = i+1;
            }
        }
    }
    if(can){
        vector<ll> qs;
        qs.pb(0);
        for(int k = j; k <= n; k++){
            qs.pb(v[k]);
        }
        int idx = 0, idx2 = 0;
        for(int k = 1; k < qs.size(); k++){
            if(!idx && qs[k] == x) idx = k;
            if(qs[k] == x) idx2 = k;
            qs[k] += qs[k-1];
        }
        map<ll,ll> mp;
        for(int k = 1; k < qs.size(); k++){
            mp[qs[k]]++;
        }
        bool go = true;
        for(int k = 1; k <= idx2; k++){
            if(qs[k]-qs[k-1] == x){
                go = true;
            }
            else if(go){
                for(int kk = k; kk <= idx2; kk++){
                    if(qs[kk]-qs[kk-1] != x) mp[qs[kk]]--;
                    else break;
                }
                go = false;
            }
            ans+=mp[s+qs[k-1]];
            if(qs[k]-qs[k-1] == x){
               mp[qs[k]]--;
            }
            //cout << s+qs[k-1] << " ";
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