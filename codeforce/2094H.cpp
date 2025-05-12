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
    int n,q;
    cin >> n >> q;
    vector<int> arr(n+1,0);
    vector<pair<pii,pii>> qq;
    vector<ll> ans(q,0);
    map<int,deque<int>> mp;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 0; i < q; i++){
        int k,l,r;
        cin >> k >> l >> r;
        qq.pb({{l,r},{k,i}});
    }
    sort(qq.begin(),qq.end());
    int cur = 0;
    for(int i = 0; i < q; i++){
        auto [lr,kidx] = qq[i];
        auto [l,r] = lr;
        auto [k,idx] = kidx;
        while(cur <= r){
            mp[arr[cur]].push_back(cur);
            cur++;
        }
        vector<int> fac;
        int temp = k;
        // find factor 
        for(int i = 2; i <= sqrt(k); i++){
            if(temp%i == 0){
                fac.pb(i);  
                fac.pb(temp/i);
            }
        }
        fac.pb(temp);
        vector<pii> cal;
        for(auto f:fac){
            while(!mp[f].empty() && mp[f].front() < l){
                mp[f].pop_front();
            }
            if(!mp[f].empty()){
                if(mp[f].front() <= r){
                    cal.pb({mp[f].front(),f});
                }
            }
        }
        sort(cal.begin(),cal.end());
        int prev = l;
        for(int i = 0; i < cal.size(); i++){
            //cout << cal[i].nd << "\n";
            ans[idx] += (cal[i].st-prev)*k;
            while(k%cal[i].nd == 0){
                k/=cal[i].nd;
            }
            prev = cal[i].st;
        }
        ans[idx] += (r-prev+1)*k;
    }
    for(auto u:ans) cout << u << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}